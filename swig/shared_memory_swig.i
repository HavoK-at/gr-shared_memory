/* -*- c++ -*- */

#define SHARED_MEMORY_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "shared_memory_swig_doc.i"

%{
#include "shared_memory/shared_memory_sink.h"
#include "shared_memory/sample_counter_test.h"
%}


%include "shared_memory/shared_memory_sink.h"
GR_SWIG_BLOCK_MAGIC2(shared_memory, shared_memory_sink);

%include "shared_memory/sample_counter_test.h"
GR_SWIG_BLOCK_MAGIC2(shared_memory, sample_counter_test);
