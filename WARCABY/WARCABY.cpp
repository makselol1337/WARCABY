#include <iostream>
using namespace std;


int main() {
	char ruch;
	char tablica[8][8] = {
		{'-', 'C', '-', 'C', '-', 'C', '-', 'C'},
		{'C', '-', 'C', '-', 'C', '-', 'C', '-'},
		{'-', 'C', '-', 'C', '-', 'C', '-', 'C'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'B', '-', 'B', '-', 'B', '-', 'B', '-'},
		{'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
		{'B', '-', 'B', '-', 'B', '-', 'B', '-'}
	};
	
	for (int rzad = 0; rzad < 8; rzad++) {
		for (int kolumna = 0; kolumna < 8; kolumna++) {
			cout << tablica[rzad][kolumna] << " ";
		}
		cout << endl;
		}
cin>> ruch;






}
