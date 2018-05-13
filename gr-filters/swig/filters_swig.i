/* -*- c++ -*- */

#define FILTERS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "filters_swig_doc.i"

%{
#include "filters/gaussian.h"
%}

%include "filters/gaussian.h"
GR_SWIG_BLOCK_MAGIC2(filters, gaussian);
