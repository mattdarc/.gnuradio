/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "im2vec_impl.h"

namespace gr {
    namespace dip {

        im2vec::sptr
        im2vec::make()
        {
            return gnuradio::get_initial_sptr
                (new im2vec_impl());
        }

        /*
         * The private constructor
         */
        im2vec_impl::im2vec_impl()
            : gr::block("im2vec",
                             gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                             gr::io_signature::make(1, 1, sizeof(cv::Mat))),
            d_sent(false)
        {}

        /*
         * Our virtual destructor.
         */
        im2vec_impl::~im2vec_impl()
        {
            d_vec.release();
            d_img.release();
        }

        int
        im2vec_impl::general_work(int noutput_items,
                          gr_vector_int &ninput_items,
                          gr_vector_const_void_star &input_items,
                          gr_vector_void_star &output_items)
        {
            const float *in = (const float *) input_items[0];
            float *out = (float *) output_items[0];
            static int i = 0;

            memcpy(&d_img, in, sizeof(d_img));

            if(this->d_sent)
            {
                return 1;
            }
            else if(d_img.empty())
            {
                std::cout << "Received empty image\n";
                return 1;
            }
            
            int rows = d_img.size[0],
                cols = d_img.size[1],
                channels = d_img.channels(),
                num_items = rows * cols * channels;
            
            // preallocate vector
            try
            {
                // add 3 for dimensions
                this->d_vec = cv::Mat(cv::Size(1, num_items + 3), CV_32S);
            }
            catch (const std::bad_alloc &e)
            {
                std::cout << "Allocation failed: " << e.what() << std::endl;
                std::cout << "Dimensions are (" << rows << ", " << cols
                          << ", " << channels << ")\n";
                std::cout << "Number of items is " << num_items+3 << std::endl;
            }

            // store header of dimensions
            this->d_vec.at< int >(0, 0) = rows;
            this->d_vec.at< int >(1, 0) = cols;
            this->d_vec.at< int >(2, 0) = channels;

            std::cout << "Started image vectorization\n";

            // convert the openCV matrix to a vector. All the images will be
            // 8-bit color so we don't need to include that
            for(int k = 0; k < channels; ++k)
            {
                for(int j = 0; j < cols; ++j)
                {
                    for(int i = 0; i < rows; ++i)
                    {
                        this->d_vec.at< int >(i + j*i + k*j*i + 3, 0) =
                            (int)d_img.at< unsigned char >(i, j, k);
                    }
                }
            }
            
            std::cout << "Finished image vectorization\n";
            std::cout << "Dimensions in vector are ("
                      << this->d_vec.at< int >(0, 0) << ", "
                      << this->d_vec.at< int >(1, 0) << ", "
                      << this->d_vec.at< int >(2, 0) << ")\n";

            // send it to the buffer
            if(d_vec.empty())
            {
                std::cout << "Empty vector\n";
                return noutput_items;
            }
            else if(!this->d_sent)
            {
                memcpy(out, &this->d_vec, sizeof(this->d_vec));
                this->d_sent = true;
                if (++i > 1) return -1;
                std::cout << "Sent image vector\n";
            }
            
            // Tell runtime system how many output items we produced.
            return noutput_items;
        }

    } /* namespace dip */
} /* namespace gr */

