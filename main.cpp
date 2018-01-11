#include "stdafx.h"
#include <systemc.h>
#include "proc1.h"
#include "proc2.h"

int sc_main(int argc, char* argv[]) {
	sc_clock clock("my_clock", 1, 0.5);

	sc_fifo<int> fifo(500);
	sc_fifo<int> fifo1(500);
	sc_fifo<int> POK1(500);
	sc_fifo<int> POK1_2(500);
	sc_fifo<int> POK4(500);
	sc_fifo<int> POK4_2(500);

	proc1 p1("p1");
	p1.clock(clock);
	p1.fifo_out(fifo);
	p1.fifo1_out(fifo1);
	p1.POK1_out(POK1);
	p1.POK4_out(POK4);
	p1.POK1_2_in(POK1_2);
	p1.POK4_2_in(POK4_2);

	proc2 p2("p2");
	p2.clock(clock);
	p2.fifo_in(fifo);
	p2.fifo1_in(fifo1);
	p2.POK1_in(POK1);
	p2.POK4_in(POK4);
	p2.POK1_2_out(POK1_2);
	p2.POK4_2_out(POK4_2);

	sc_start();
	system("pause");

	return 0;

}
