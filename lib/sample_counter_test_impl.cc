/* -*- c++ -*- */
/* MIT License
 * 
 * Copyright (c) 2018 Markus
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "sample_counter_test_impl.h"

namespace gr
{
namespace shared_memory
{

sample_counter_test::sptr
sample_counter_test::make(size_t itemsize)
{
    return gnuradio::get_initial_sptr(new sample_counter_test_impl(itemsize));
}

/*
     * The private constructor
     */
sample_counter_test_impl::sample_counter_test_impl(size_t itemsize)
    : gr::sync_block("sample_counter_test",
                     gr::io_signature::make(1, 1, itemsize),
                     gr::io_signature::make(0, 0, 0)),
      _itemsize(itemsize),
      _samples_consumed(0)
{
    _start = std::chrono::system_clock::now();
}

/*
     * Our virtual destructor.
     */
sample_counter_test_impl::~sample_counter_test_impl()
{
}

int sample_counter_test_impl::work(int noutput_items,
                                   gr_vector_const_void_star &input_items,
                                   gr_vector_void_star &output_items)
{
    auto temp_start = std::chrono::system_clock::now();
    _elapsed_seconds = temp_start - _start;

    if (_elapsed_seconds.count() >= 1)
    {
        std::cout << "Size (" << _itemsize << " B): " << _samples_consumed << " S/s" << std::endl;
        _start = temp_start;
        _samples_consumed = 0;
    }
    _samples_consumed += noutput_items;
    consume_each(noutput_items);
    return 0;
}

} /* namespace shared_memory */
} /* namespace gr */
