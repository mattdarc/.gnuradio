#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/matt_darc/.gnuradio/gr-dip/lib
export PATH=/home/matt_darc/.gnuradio/gr-dip/build/lib:$PATH
export LD_LIBRARY_PATH=/home/matt_darc/.gnuradio/gr-dip/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-dip 
