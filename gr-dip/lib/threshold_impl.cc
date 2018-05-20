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
#include "threshold_impl.h"

namespace gr {
  namespace dip {

    threshold::sptr
    threshold::make(float thresh, int method)
    {
      return gnuradio::get_initial_sptr
        (new threshold_impl(thresh, method));
    }

    /*
     * The private constructor
     */
    threshold_impl::threshold_impl(float thresh, int method)
      : gr::sync_block("threshold",
                       gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                       gr::io_signature::make(1, 1, sizeof(cv::Mat))),
      d_thresh(thresh), d_method((ThreshMethod)method)
    {}

    /*
     * Our virtual destructor.
     */
    threshold_impl::~threshold_impl()
    {
      d_img.release();
      d_result.release();
    }

    int
    threshold_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const cv::Mat *in = (const cv::Mat *) input_items[0];
      cv::Mat *out = (cv::Mat *) output_items[0];
      memcpy(&d_img, in, sizeof(d_img));

      // Do <+signal processing+>
      if(d_img.empty())
        {
          std::cout << "Received empty image\n";
          return 1;
        } else
        {
          // make sure that it is a grayscale image

          // threshold the image
          cv::threshold(d_img, d_result, d_thresh*255,
                        255 /* max binary value */,
                        (int)d_method);
        }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace dip */
} /* namespace gr */
