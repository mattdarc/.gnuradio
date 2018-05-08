#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/matt_darc/.gnuradio/gr-imcompression/python
export PATH=/home/matt_darc/.gnuradio/gr-imcompression/build/python:$PATH
export LD_LIBRARY_PATH=/home/matt_darc/.gnuradio/gr-imcompression/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/matt_darc/.gnuradio/gr-imcompression/build/swig:$PYTHONPATH
/usr/bin/python2 /home/matt_darc/.gnuradio/gr-imcompression/python/qa_lzw_comp.py 
