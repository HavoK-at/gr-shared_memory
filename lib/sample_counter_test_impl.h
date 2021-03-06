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

#ifndef INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_IMPL_H
#define INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_IMPL_H

#include <shared_memory/sample_counter_test.h>
#include <chrono>
#include <ctime>

namespace gr
{
namespace shared_memory
{

class sample_counter_test_impl : public sample_counter_test
{
  private:
    size_t _itemsize;
    unsigned long _samples_consumed;
    std::chrono::duration<double> _elapsed_seconds;
    std::chrono::system_clock::time_point _start;

  public:
    sample_counter_test_impl(size_t itemsize);
    ~sample_counter_test_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star &input_items,
             gr_vector_void_star &output_items);
};

} // namespace shared_memory
} // namespace gr

#endif /* INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_IMPL_H */
