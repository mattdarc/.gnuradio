/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
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
#include "image_sink_impl.h"

namespace gr {
    namespace dip {

        image_sink::sptr
        image_sink::make()
        {
            return gnuradio::get_initial_sptr
                (new image_sink_impl());
        }

        /*
         * The private constructor
         */
        image_sink_impl::image_sink_impl()
            : gr::block("image_sink",
                        gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                        gr::io_signature::make(0, 0, 0))
        {}

        /*
         * Our virtual destructor.
         */
        image_sink_impl::~image_sink_impl()
        {
        }

        void
        image_sink_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
        {
            /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
        }

        int
        image_sink_impl::general_work (int noutput_items,
                                       gr_vector_int &ninput_items,
                                       gr_vector_const_void_star &input_items,
                                       gr_vector_void_star &output_items)
        {
            float *in = (float *) input_items[0];
            memcpy(&d_img, in, sizeof(d_img));
      
            if(d_img.empty())
            {
                std::cout << "Sink received empty image\n";
                return 1;
            }
            else
            {
                cv::namedWindow("Output Image", cv::WINDOW_AUTOSIZE);
                cv::imshow("Output Image", d_img);
                cv::waitKey(0);
                consume_each (noutput_items);
            }
        
            // Tell runtime system how many output items we produced.
            return noutput_items;
        }

    } /* namespace dip */
} /* namespace gr */

