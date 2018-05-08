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

#ifndef INCLUDED_DIP_IMAGE_SAVE_IMPL_H
#define INCLUDED_DIP_IMAGE_SAVE_IMPL_H

#include <dip/image_save.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace gr {
    namespace dip {

        class image_save_impl : public image_save
        {
        private:
            cv::Mat d_img;
            const char *d_filename;

        public:
            image_save_impl(const char *filename);
            ~image_save_impl();

            // Where all the action really happens
            void forecast (int noutput_items, gr_vector_int &ninput_items_required);

            int general_work(int noutput_items,
                             gr_vector_int &ninput_items,
                             gr_vector_const_void_star &input_items,
                             gr_vector_void_star &output_items);
        };

    } // namespace dip
} // namespace gr

#endif /* INCLUDED_DIP_IMAGE_SAVE_IMPL_H */

