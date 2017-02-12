/* -*- c++ -*- */
/* @file
 * @author Piotr Krysik <ptrkrysik@gmail.com>
 * @section LICENSE
 * 
 * Gr-gsm is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * Gr-gsm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with gr-gsm; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 * 
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "final_printer_impl.h"

namespace gr {
  namespace grgsm {

    final_printer::sptr
    final_printer::make()
    {
      return gnuradio::get_initial_sptr
        (new final_printer_impl());
    }
    
    void final_printer_impl::message_print(pmt::pmt_t msg)
    {
        std::cout << pmt::symbol_to_string(msg) << std::endl;
    }

    /*
     * The private constructor
     */
    final_printer_impl::final_printer_impl()
      : gr::sync_block("final_printer",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(0, 0, 0))
    {
        message_port_register_in(pmt::mp("print"));
        set_msg_handler(pmt::mp("print"), boost::bind(&final_printer_impl::message_print, this, _1));
    }

    /*
     * Our virtual destructor.
     */
    final_printer_impl::~final_printer_impl()
    {
    }

    int
    final_printer_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
//      const <+ITYPE+> *in = (const <+ITYPE+> *) input_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace grgsm */
} /* namespace gr */

