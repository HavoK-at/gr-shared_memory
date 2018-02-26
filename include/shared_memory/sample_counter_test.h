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


#ifndef INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_H
#define INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_H

#include <shared_memory/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace shared_memory {

    /*!
     * \brief <+description of block+>
     * \ingroup shared_memory
     *
     */
    class SHARED_MEMORY_API sample_counter_test : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<sample_counter_test> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of shared_memory::sample_counter_test.
       *
       * To avoid accidental use of raw pointers, shared_memory::sample_counter_test's
       * constructor is in a private implementation
       * class. shared_memory::sample_counter_test::make is the public interface for
       * creating new instances.
       */
      static sptr make(size_t itemsize);
    };

  } // namespace shared_memory
} // namespace gr

#endif /* INCLUDED_SHARED_MEMORY_SAMPLE_COUNTER_TEST_H */

