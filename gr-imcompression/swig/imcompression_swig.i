/* -*- c++ -*- */

#define IMCOMPRESSION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "imcompression_swig_doc.i"

%{
#include "imcompression/lzw.h"
#include "imcompression/inv_lzw.h"
%}

%include "imcompression/lzw.h"
GR_SWIG_BLOCK_MAGIC2(imcompression, lzw);
%include "imcompression/inv_lzw.h"
GR_SWIG_BLOCK_MAGIC2(imcompression, inv_lzw);
