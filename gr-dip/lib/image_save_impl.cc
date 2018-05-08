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
#include "image_save_impl.h"

namespace gr {
    namespace dip {

        image_save::sptr
        image_save::make(const char *filename)
        {
            return gnuradio::get_initial_sptr
                (new image_save_impl(filename));
        }

        /*
         * The private constructor
         */
        image_save_impl::image_save_impl(const char *filename)
            : gr::block("image_save",
                        gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                        gr::io_signature::make(0, 0, 0)), d_filename(filename)
        {}

        /*
         * Our virtual destructor.
         */
        image_save_impl::~image_save_impl()
        {
        }

        void
        image_save_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
        {
            /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
        }

        int
        image_save_impl::general_work (int noutput_items,
                                       gr_vector_int &ninput_items,
                                       gr_vector_const_void_star &input_items,
                                       gr_vector_void_star &output_items)
        {
            const cv::Mat *in = (const cv::Mat *) input_items[0];
            memcpy(&d_img, in, sizeof(d_img));
            
            if(d_img.empty())
            {
                std::cout << "Sink received empty image\n";
                return 1;
            } else
            {
                std::cout << "Wrote image to " << this->d_filename << std::endl;
                cv::imwrite(this->d_filename, this->d_img);
            }
            // Do <+signal processing+>
            // Tell runtime system how many input items we consumed on
            // each input stream.
            consume_each (noutput_items);

            // Tell runtime system how many output items we produced.
            return noutput_items;
        }

    } /* namespace dip */
} /* namespace gr */

