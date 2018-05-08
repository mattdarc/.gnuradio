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

#ifndef INCLUDED_DIP_VEC2IM_IMPL_H
#define INCLUDED_DIP_VEC2IM_IMPL_H

#include <dip/vec2im.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace gr {
    namespace dip {

        class vec2im_impl : public vec2im
        {
        private:
            cv::Mat d_vec;
            cv::Mat d_img;
            bool d_sent;

        public:
            vec2im_impl();
            ~vec2im_impl();

            // Where all the action really happens
            int general_work(int noutput_items,
                             gr_vector_int &ninput_items,
                             gr_vector_const_void_star &input_items,
                             gr_vector_void_star &output_items);
        };

    } // namespace dip
} // namespace gr

#endif /* INCLUDED_DIP_VEC2IM_IMPL_H */

