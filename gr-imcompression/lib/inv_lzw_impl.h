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

#ifndef INCLUDED_IMCOMPRESSION_INV_LZW_IMPL_H
#define INCLUDED_IMCOMPRESSION_INV_LZW_IMPL_H

#include <imcompression/inv_lzw.h>

namespace gr {
  namespace imcompression {

    class inv_lzw_impl : public inv_lzw
    {
     private:
      // Nothing to declare in this block.

     public:
      inv_lzw_impl(int bit_num);
      ~inv_lzw_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace imcompression
} // namespace gr

#endif /* INCLUDED_IMCOMPRESSION_INV_LZW_IMPL_H */

