/* -*- c++ -*- */

#define DIP_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "dip_swig_doc.i"

%{
#include "dip/image_source.h"
#include "dip/image_sink.h"
#include "dip/image_save.h"
#include "dip/image_throttle.h"
#include "dip/gaussian.h"
#include "dip/median.h"
#include "dip/threshold.h"
#include "dip/gradient.h"
#include "dip/rgb2gray.h"
#include "dip/gradient_magnitude.h"
#include "dip/gradient_phase.h"
%}


%include "dip/image_source.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_source);
%include "dip/image_sink.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_sink);
%include "dip/image_save.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_save);

%include "dip/image_throttle.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_throttle);
%include "dip/gaussian.h"
GR_SWIG_BLOCK_MAGIC2(dip, gaussian);
%include "dip/median.h"
GR_SWIG_BLOCK_MAGIC2(dip, median);

%include "dip/threshold.h"
GR_SWIG_BLOCK_MAGIC2(dip, threshold);
%include "dip/gradient.h"
GR_SWIG_BLOCK_MAGIC2(dip, gradient);
%include "dip/rgb2gray.h"
GR_SWIG_BLOCK_MAGIC2(dip, rgb2gray);
%include "dip/gradient_magnitude.h"
GR_SWIG_BLOCK_MAGIC2(dip, gradient_magnitude);
%include "dip/gradient_phase.h"
GR_SWIG_BLOCK_MAGIC2(dip, gradient_phase);
