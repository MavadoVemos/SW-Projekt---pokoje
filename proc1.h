#pragma once
#include <systemc.h>
#include "naszmodul.h"

SC_MODULE(proc1) {
	sc_in_clk clock;
	sc_fifo_out<int> fifo_out;
	sc_fifo_out<int> fifo1_out;
	sc_fifo_out<int> POK1_out;
	sc_fifo_out<int> POK4_out;
	sc_fifo_in<int> POK1_2_in;
	sc_fifo_in<int> POK4_2_in;

	naszmodul modul;
	sc_signal<sc_int<8>> state;
	sc_signal<sc_int<8>> dir;
	sc_signal<sc_int<8>> POK3;
	//sc_in<sc_int<8>> POK3_2;
	int pok1 = 0;
	int pok2 = 0;
	int pok3 = 0;
	int pok4 = 0;
	int kierunek = 1;

	void task1();
	void task2();

	SC_CTOR(proc1)
		: modul("modul")
	{
		state.write(0);
		dir.write(0);
		POK3.write(0);
		modul.clock(clock);
		modul.state(state);
		modul.dir(dir);
		modul.POK3(POK3);
		

		SC_THREAD(task1);
		sensitive << clock.pos();

		SC_METHOD(task2);
		sensitive << clock.pos();

	}

};
