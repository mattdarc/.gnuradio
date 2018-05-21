#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Top Block
# Generated: Sun May 20 20:31:41 2018
##################################################

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
        self.thresh = thresh = 100
        self.samp_rate = samp_rate = 60

        ##################################################
        # Blocks
        ##################################################
        self.dip_threshold_0 = dip.threshold(thresh, 0)
        self.dip_rgb2gray_0 = dip.rgb2gray()
        self.dip_image_throttle_0 = dip.image_throttle(samp_rate,True)
        self.dip_image_source_0 = dip.image_source('/home/matthew/MEGA/ecse-4540/hw/hw5/curling.jpg')
        self.dip_image_sink_0 = dip.image_sink()
        self.dip_gradient_magnitude_0 = dip.gradient_magnitude()
        self.dip_gradient_0 = dip.gradient(0)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.dip_gradient_0, 0), (self.dip_gradient_magnitude_0, 0))
        self.connect((self.dip_gradient_0, 1), (self.dip_gradient_magnitude_0, 1))
        self.connect((self.dip_gradient_magnitude_0, 0), (self.dip_threshold_0, 0))
        self.connect((self.dip_image_source_0, 0), (self.dip_image_throttle_0, 0))
        self.connect((self.dip_image_throttle_0, 0), (self.dip_rgb2gray_0, 0))
        self.connect((self.dip_rgb2gray_0, 0), (self.dip_gradient_0, 0))
        self.connect((self.dip_threshold_0, 0), (self.dip_image_sink_0, 0))

    def get_thresh(self):
        return self.thresh

    def set_thresh(self, thresh):
        self.thresh = thresh

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.dip_image_throttle_0.set_sample_rate(self.samp_rate)


def main(top_block_cls=top_block, options=None):

    tb = top_block_cls()
    tb.start()
    tb.wait()


if __name__ == '__main__':
    main()
