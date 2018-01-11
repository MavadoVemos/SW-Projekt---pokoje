#include "stdafx.h"
#include "proc1.h"

void proc1::task1() {
	int input = 0;
	char kierunek1[12] = "lewo - gora";
	char kierunek2[12] = "prawo - dol";
	char* kierunek3;
	int i = 0;

	while (true) {

		if (i == 1) {		
			POK1_out.write(pok1);
			POK4_out.write(pok4);
		}

		wait();
		
		if (i == 1) {	
			pok1 = POK1_2_in.read();
			pok4 = POK4_2_in.read();
		}

		if (kierunek == 1) {
			kierunek3 = kierunek1;
		}
		else {
			kierunek3 = kierunek2;
		}	
	
		system("cls");
		cout << "Wybierz jakimi drzwiami chcesz przejcs: \n\n";
		cout << "Aktualny kierunek przejscia: " << kierunek3 << "\n\n";
		cout << "Drzwi 1\nDrzwi 2\nDrzwi 3\nDrzwi 4\nDrzwi 5\nDrzwi 6\nDrzwi 7\nZmien kierunek przejscia 8\n" << endl;
		cout << "Ilosc osob w pokojach\nPok1: " << pok1 << "\nPok2: " << pok2 << "\nPok3: " << pok3 << "\nPok4: " << pok4 << "\n\n" << endl;
		
		cin >> input;

		if (input == 8) {
			if (kierunek == 1) {
				kierunek = 2;
			}
			else {
				kierunek = 1;
			}
			cout << "zmieniono kierunek: " << kierunek << endl;
		}

		if (input == 7) {
			if (kierunek == 1) {
				if (pok1 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok1--;
					pok3++;
				}
			}
			else {
				if (pok3 < 1) {
					cout << "Error! 0 osob w pokoju !" << endl;
				}
				else {
					pok3--;
					pok1++;
				}
			}
		}

		dir.write(kierunek);		
		POK3.write(pok3);	
		state.write(input);
		fifo_out.write(input);
		fifo1_out.write(kierunek);		
		i=1;
	}
}

void proc1::task2() {
	
	if (state.read() == 2) {
		if (kierunek == 1) {
			pok2++;
		}
		else {
			if (pok2 < 1) {
				cout << "Error! 0 osob w pokoju !" << endl;
			}
			else {
				pok2--;
			}
		}
	}

	if (state.read() == 1) {
		if (kierunek == 1) {
			if (pok2 < 1) {
				cout << "Error! 0 osob w pokoju !" << endl;
			}
			else
			{
				pok2--;
				pok3++;
			}
		}
		else {
			if (pok3 < 1) {
				cout << "Error! 0 osob w pokoju !" << endl;
			}
			else {
				pok3--;
				pok2++;
			}
		}
	}
}


