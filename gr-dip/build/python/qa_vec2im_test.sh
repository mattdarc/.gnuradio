#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/matt_darc/.gnuradio/gr-dip/python
export PATH=/home/matt_darc/.gnuradio/gr-dip/build/python:$PATH
export LD_LIBRARY_PATH=/home/matt_darc/.gnuradio/gr-dip/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/matt_darc/.gnuradio/gr-dip/build/swig:$PYTHONPATH
/usr/bin/python2 /home/matt_darc/.gnuradio/gr-dip/python/qa_vec2im.py 
