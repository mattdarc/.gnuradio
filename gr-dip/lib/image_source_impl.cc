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
#include "image_source_impl.h"

namespace gr {
    namespace dip {

        image_source::sptr
        image_source::make(const char *filename)
        {
            return gnuradio::get_initial_sptr
                (new image_source_impl(filename));
        }

        /*
         * The private constructor
         */
        image_source_impl::image_source_impl(const char *filename)
            : gr::block("image_source",
                        gr::io_signature::make(0,0,0),
                        gr::io_signature::make(1, 1, sizeof(cv::Mat))),
            d_sent(false)
        {
            d_img = cv::imread(filename, 1);
            if(!d_img.data)
            {
                throw std::runtime_error ("Can't open image file");
            }
        }

        /*
         * Our virtual destructor.
         */
        image_source_impl::~image_source_impl()
        {
            d_img.release();
        }

        void
        image_source_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
        {
            /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
        }

        int
        image_source_impl::general_work (int noutput_items,
                                         gr_vector_int &ninput_items,
                                         gr_vector_const_void_star &input_items,
                                         gr_vector_void_star &output_items)
        {
            float *out = (float *) output_items[0];
            static int i = 0;
      
            if(d_img.empty())
            {
                std::cout << "Empty source image\n";
                return noutput_items;
            }
            else if(!this->d_sent)
            {
                memcpy(out, &d_img, sizeof(d_img));
                this->d_sent = true;
                if (++i > 1) return -1;
            
            }
            return noutput_items;
        }

    } /* namespace dip */
} /* namespace gr */

