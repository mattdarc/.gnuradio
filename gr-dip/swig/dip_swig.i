/* -*- c++ -*- */

#define DIP_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "dip_swig_doc.i"

%{
#include "dip/image_source.h"
#include "dip/image_sink.h"
#include "dip/image_save.h"
#include "dip/im2vec.h"
#include "dip/vec2im.h"
#include "dip/image_throttle.h"
%}


%include "dip/image_source.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_source);
%include "dip/image_sink.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_sink);
%include "dip/image_save.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_save);

%include "dip/im2vec.h"
GR_SWIG_BLOCK_MAGIC2(dip, im2vec);
%include "dip/vec2im.h"
GR_SWIG_BLOCK_MAGIC2(dip, vec2im);
%include "dip/image_throttle.h"
GR_SWIG_BLOCK_MAGIC2(dip, image_throttle);
