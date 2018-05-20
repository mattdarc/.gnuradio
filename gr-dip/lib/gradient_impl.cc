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
#include "gradient_impl.h"

namespace gr {
  namespace dip {

    gradient::sptr
    gradient::make(int method)
    {
      return gnuradio::get_initial_sptr
        (new gradient_impl(method));
    }

    /*
     * The private constructor
     */
    gradient_impl::gradient_impl(int method)
      : gr::sync_block("gradient",
                       gr::io_signature::make(1, 1, sizeof(cv::Mat)),
                       gr::io_signature::make(2, 2, sizeof(cv::Mat))),
      d_method(Sobel)
    {}

    /*
     * Our virtual destructor.
     */
    gradient_impl::~gradient_impl()
    {
      d_img.release();
      d_grad_x.release();
      d_grad_y.release();
    }

    int
    gradient_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const cv::Mat *in = (const cv::Mat *) input_items[0];
      cv::Mat *outX = (cv::Mat *) output_items[0];
      cv::Mat *outY = (cv::Mat *) output_items[1];
      memcpy(&d_img, in, sizeof(d_img));

      if(d_img.empty())
        {
          std::cout << "Received empty image\n";
          return 1;
        } else
        {
          // make sure that it is a grayscale image

          // Get the gradient of the image with the designated method
          switch(d_method)
            {
            case Sobel:
              cv::Sobel(d_img, d_grad_x, CV_16S, 1, 0, 3, 1, cv::BORDER_DEFAULT);
              cv::Sobel(d_img, d_grad_y, CV_16S, 0, 1, 3, 1, cv::BORDER_DEFAULT);
              break;
            case Prewitt:
            default:
              std::cout << "Unknown gradient method\n";
              return 1;
            }
          // memcpy(out, &d_result, sizeof(d_result));
          outX = &d_grad_x;
          outY = &d_grad_y;
        }


      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace dip */
} /* namespace gr */
