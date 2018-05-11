#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/matthew/.gnuradio/gr-dip/lib
export PATH=/home/matthew/.gnuradio/gr-dip/build/lib:$PATH
export LD_LIBRARY_PATH=/home/matthew/.gnuradio/gr-dip/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-dip 
