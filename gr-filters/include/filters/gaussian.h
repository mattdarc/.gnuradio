/* -*- c++ -*- */
/*
 * Copyright 2018 gr-filters author.
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


#ifndef INCLUDED_FILTERS_GAUSSIAN_H
#define INCLUDED_FILTERS_GAUSSIAN_H

#include <filters/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace filters {

    /*!
     * \brief <+description of block+>
     * \ingroup filters
     *
     */
    class FILTERS_API gaussian : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<gaussian> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of filters::gaussian.
       *
       * To avoid accidental use of raw pointers, filters::gaussian's
       * constructor is in a private implementation
       * class. filters::gaussian::make is the public interface for
       * creating new instances.
       */
      static sptr make(float sigma, size_t n);
    };

  } // namespace filters
} // namespace gr

#endif /* INCLUDED_FILTERS_GAUSSIAN_H */
