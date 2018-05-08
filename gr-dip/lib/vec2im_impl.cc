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
#include "vec2im_impl.h"

namespace gr {
    namespace dip {

        vec2im::sptr
        vec2im::make()
        {
            return gnuradio::get_initial_sptr
                (new vec2im_impl());
        }

        /*
         * The private constructor
         */
        vec2im_impl::vec2im_impl()
            : gr::block("vec2im",
                        gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                        gr::io_signature::make(1, 1, sizeof(cv::Mat)))
        {}

        /*
         * Our virtual destructor.
         */
        vec2im_impl::~vec2im_impl()
        {
            d_vec.release();
            d_img.release();
        }

        int
        vec2im_impl::general_work(int noutput_items,
                                  gr_vector_int &ninput_items,
                                  gr_vector_const_void_star &input_items,
                                  gr_vector_void_star &output_items)
        {
            std::cout << "Getting image data from vector\n";
            
            const float *in = (const float *) input_items[0];
            float *out = (float *) output_items[0];
            static int i = 0;

            memcpy(&d_vec, in, sizeof(d_vec));

            if(this->d_sent)
            {
                return 1;
            }
            else if(d_vec.empty())
            {
                std::cout << "Received empty image\n";
                return 1;
            }
            
            std::cout << " Size is " << d_vec.size() << std::endl;

            
            int rows = d_vec.at<int>(0,0),
                cols = d_vec.at<int>(1,0),
                channels = d_vec.at<int>(2,0);
            int sz[] = {rows, cols, channels};
                
            std::cout << "Received vector of (" << rows << ", " << cols
                      << ", " << channels << ") image\n";

            std::cout << "Starting image construction\n";
            this->d_img = cv::Mat(3, sz, CV_8U, cv::Scalar::all(0));
            for(int k = 0; k < channels; ++k)
            {
                for(int j = 0; j < cols; ++j)
                {
                    for(int i = 0; i < rows; ++i)
                    {
                        d_img.at<unsigned char>(i, j, k) =
                            (unsigned char)d_vec.at<int>(3 + i + j*i + k*j*i, 0);
                    }
                }
            }

            std::cout << "Finished image construction\n";
            
            // send it to the buffer
            if(d_img.empty())
            {
                std::cout << "Empty image\n";
                return noutput_items;
            }
            else if(!this->d_sent)
            {
                memcpy(out, &this->d_img, sizeof(this->d_img));
                this->d_sent = true;
                if (++i > 1) return -1;
                std::cout << "Sent image\n";
            }

            // Tell runtime system how many output items we produced.
            return noutput_items;
        }

    } /* namespace dip */
} /* namespace gr */

