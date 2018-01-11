#include "stdafx.h"
#include "naszmodul.h"

void naszmodul::task() {
	int temp = state.read();
	kierunek = dir.read();
	pok3 = POK3.read();

	if (temp == 6) {
		if (kierunek == 1) {
			if (pok3 < 1) {
				cout << "Error! 0 osob w pokoju !" << endl;
				
			}
			else {
				pok3--;
			}
		}
		else {
			pok3++;
		}
		
		//POK3_out.write(pok3);
	}

	
}