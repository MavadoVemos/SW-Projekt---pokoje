#include "stdafx.h"
#include "proc1.h"

void proc1::task1() {
	int input = 0;
	char kierunek1[12] = "lewo - gora";
	char kierunek2[12] = "prawo - dol";
	char* kierunek3;

	while (true) {
		

		wait();

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

		if (input == 4 || input == 3 || input == 5) {
			pok4 = POK4_2_in.read();

			if (input == 5) {
				pok1 = POK1_2_in.read();
			}
		}


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
					cout << "pok1 wlazlo" << endl;
				}
			}
		}

		dir.write(kierunek);
		POK1_out.write(pok1);
		POK3.write(pok3);
		POK4_out.write(pok4);
		state.write(input);
		fifo_out.write(state.read());
		fifo1_out.write(kierunek);

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


