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


#ifndef INCLUDED_DIP_THRESHOLD_H
#define INCLUDED_DIP_THRESHOLD_H

#include <dip/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace dip {

    /*!
     * \brief <+description of block+>
     * \ingroup dip
     *
     */
    class DIP_API threshold : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<threshold> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of dip::threshold.
       *
       * To avoid accidental use of raw pointers, dip::threshold's
       * constructor is in a private implementation
       * class. dip::threshold::make is the public interface for
       * creating new instances.
       */
      static sptr make(unsigned char thresh, int method);
    };

  } // namespace dip
} // namespace gr

#endif /* INCLUDED_DIP_THRESHOLD_H */
