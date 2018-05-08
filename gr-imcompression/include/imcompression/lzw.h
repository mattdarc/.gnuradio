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


#ifndef INCLUDED_IMCOMPRESSION_LZW_H
#define INCLUDED_IMCOMPRESSION_LZW_H

#include <imcompression/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace imcompression {

    /*!
     * \brief <+description of block+>
     * \ingroup imcompression
     *
     */
    class IMCOMPRESSION_API lzw : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<lzw> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of imcompression::lzw.
       *
       * To avoid accidental use of raw pointers, imcompression::lzw's
       * constructor is in a private implementation
       * class. imcompression::lzw::make is the public interface for
       * creating new instances.
       */
      static sptr make(int bit_num);
    };

  } // namespace imcompression
} // namespace gr

#endif /* INCLUDED_IMCOMPRESSION_LZW_H */

