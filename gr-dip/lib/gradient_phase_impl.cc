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
#include "gradient_phase_impl.h"

namespace gr {
  namespace dip {

    gradient_phase::sptr
    gradient_phase::make()
    {
      return gnuradio::get_initial_sptr
        (new gradient_phase_impl());
    }

    /*
     * The private constructor
     */
    gradient_phase_impl::gradient_phase_impl()
      : gr::sync_block("gradient_phase",
                       gr::io_signature::make(2, 2, sizeof(cv::Mat)),
                       gr::io_signature::make(1, 1, sizeof(cv::Mat))),
      d_sent(false)
    {}

    /*
     * Our virtual destructor.
     */
    gradient_phase_impl::~gradient_phase_impl()
    {
      d_result.release();
      d_dx.release();
      d_dy.release();
    }

    int
    gradient_phase_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const cv::Mat *inX = (const cv::Mat *) input_items[0];
      const cv::Mat *inY = (const cv::Mat *) input_items[1];
      cv::Mat *out = (cv::Mat *) output_items[0];
      static int i = 0;
      memcpy(&d_dx, inX, sizeof(d_dx));
      memcpy(&d_dy, inY, sizeof(d_dy));

      // Do <+signal processing+>
      if((d_dx.empty() || d_dy.empty()) && !d_sent)
        {
          std::cout << "Received empty image\n";
          return 1;
        }
      else if(!d_sent)
        {
          // make sure that it is a grayscale image
          if(d_dx.channels() != 1 || d_dy.channels() != 1)
            {
              // image is not grayscale
              throw std::runtime_error ("Too many channels, not grayscale image");
            }

          // get the magnitude of the gradients
          cv::phase(d_dx, d_dy, d_result);

          // send to buffer
          memcpy(out, &d_result, sizeof(d_result));
          if (++i > 1) return -1;
          d_sent = true;

          // Tell runtime system how many input items we consumed on
          // each input stream.
          consume_each (noutput_items);
        }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace dip */
} /* namespace gr */
