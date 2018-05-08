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

#ifndef INCLUDED_IMCOMPRESSION_LZW_IMPL_H
#define INCLUDED_IMCOMPRESSION_LZW_IMPL_H

#include <imcompression/lzw.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace gr {
    namespace imcompression {

        class lzw_impl : public lzw
        {
            typedef struct
            {
                TrieNode *children[256];  // our alphabet size is 256 (0 - 255)

                // true if the node is the end of a word
                bool is_eow
            } TrieNode;
            
        private:
            int add_code(int last, int current); // return 0 on success
            int find_code(int last, int current); // return -1 on fail
            void create_dict();
            std::vector<int> compress(const cv::Mat &im);
            
            int d_bit_num;
            std::vector<TrieNode> code_dict;
        public:
            lzw_impl(int bit_num);
            ~lzw_impl();

            // Where all the action really happens
            int work(int noutput_items,
                     gr_vector_const_void_star &input_items,
                     gr_vector_void_star &output_items);
        };

    } // namespace imcompression
} // namespace gr

#endif /* INCLUDED_IMCOMPRESSION_LZW_IMPL_H */

