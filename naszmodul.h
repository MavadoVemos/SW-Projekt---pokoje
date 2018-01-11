#pragma once
#include <systemc.h>

SC_MODULE(naszmodul) {
	sc_in_clk clock;
	sc_in<sc_int<8>> state;
	sc_in<sc_int<8>> dir;
	sc_in<sc_int<8>> POK3;
	//sc_signal<sc_int<8>> POK3_2;

	int pok3 = 0;
	int kierunek = 1;
	void task();
	

	SC_CTOR(naszmodul) {

		SC_METHOD(task);
		sensitive << clock.pos();
	}

};
