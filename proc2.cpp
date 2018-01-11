#include "stdafx.h"
#include "proc2.h"

void proc2::task() {
	
	while (true) {
		int temp = fifo_in.read();
		kierunek = fifo1_in.read();
		
		pok1 = POK1_in.read();
		pok4 = POK4_in.read();

		if (temp == 3) {		
			if (kierunek == 1) {
				pok4++;
			}
			else {
				if (pok4 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok4--;
				}
			}		
		}

		if (temp == 4) {
			if (kierunek == 1) {
				pok4++;
			}
			else {
				if (pok4 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok4--;
				}
			}
		}

		if (temp == 5) {
			if (kierunek == 1) {
				if (pok4 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok4--;
					pok1++;
				}
			}
			else {
				if (pok1 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok1--;
					pok4++;
				}
			}
		}
			
		POK1_2_out.write(pok1);		
		POK4_2_out.write(pok4);

	}
}