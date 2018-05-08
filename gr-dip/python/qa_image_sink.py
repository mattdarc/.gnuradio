#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2018 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import dip_swig as dip


class qa_image_sink (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
        filename = '/home/matt_darc/MEGA/ecse-4540/proj/gray/artificial.pgm'
        filename_out =
        '/home/matt_darc/MEGA/ecse-4540/proj/gray/artificial_out.pgm'
        src = dip.image_source(filename)
        snk = dip.image_sink(filename_out)
        self.tb.connect(src, snk)
        print 'running'
        self.tb.run()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_image_sink, "qa_image_sink.xml")
