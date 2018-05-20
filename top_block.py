#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Top Block
# Generated: Sun May 20 15:51:56 2018
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import dip


class top_block(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "Top Block")

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 60

        ##################################################
        # Blocks
        ##################################################
        self.dip_threshold_0 = dip.threshold(0.4, 0)
        self.dip_image_throttle_0 = dip.image_throttle(samp_rate,True)
        self.dip_image_source_0 = dip.image_source('/home/matthew/MEGA/ecse-4540/hw/hw5/curling.jpg')
        self.dip_image_sink_0 = dip.image_sink()
        self.dip_gradient_0 = dip.gradient(sobel)
        self.blocks_float_to_complex_0 = blocks.float_to_complex(1)
        self.blocks_complex_to_mag_0 = blocks.complex_to_mag(1)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_complex_to_mag_0, 0), (self.dip_threshold_0, 0))
        self.connect((self.blocks_float_to_complex_0, 0), (self.blocks_complex_to_mag_0, 0))
        self.connect((self.dip_gradient_0, 0), (self.blocks_float_to_complex_0, 0))
        self.connect((self.dip_gradient_0, 1), (self.blocks_float_to_complex_0, 1))
        self.connect((self.dip_image_source_0, 0), (self.dip_image_throttle_0, 0))
        self.connect((self.dip_image_throttle_0, 0), (self.dip_gradient_0, 0))
        self.connect((self.dip_threshold_0, 0), (self.dip_image_sink_0, 0))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.dip_image_throttle_0.set_sample_rate(self.samp_rate)


def main(top_block_cls=top_block, options=None):

    tb = top_block_cls()
    tb.start()
    try:
        raw_input('Press Enter to quit: ')
    except EOFError:
        pass
    tb.stop()
    tb.wait()


if __name__ == '__main__':
    main()
