#pragma once
#include <systemc.h>

SC_MODULE(proc2) {
	sc_in_clk clock;
	sc_fifo_in<int> fifo_in;
	sc_fifo_in<int> fifo1_in;
	sc_fifo_in<int> POK1_in;
	sc_fifo_in<int> POK4_in;
	sc_fifo_out<int> POK1_2_out;
	sc_fifo_out<int> POK4_2_out;
	
	int pok1 = 0;
	int pok4 = 0;
	int kierunek;

	void task();
	

	SC_CTOR(proc2) {

		SC_THREAD(task);
		sensitive << clock.pos();
	}

};
