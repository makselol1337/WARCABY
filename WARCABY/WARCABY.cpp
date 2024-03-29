#include <iostream>
using namespace std;

void wyswietl_plansze(char tablica[8][8]) { //wyswietla numerki do planszy
    cout << "   0 1 2 3 4 5 6 7" << endl;
    for (int rzad = 0; rzad < 8; rzad++) {
        cout << rzad << "  ";
        for (int kolumna = 0; kolumna < 8; kolumna++) {
            cout << tablica[rzad][kolumna] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool czy_ruch_dozwolony(char gracz, int start_rzad, int start_kolumna, int cel_rzad, int cel_kolumna, char tablica[8][8]) {
    if (start_rzad < 0 || start_rzad >= 8 || start_kolumna < 0 || start_kolumna >= 8 ||
        cel_rzad < 0 || cel_rzad >= 8 || cel_kolumna < 0 || cel_kolumna >= 8) {
        return false;  // dobre wspolrzedne ? :3
    }

    if (tablica[start_rzad][start_kolumna] != gracz || tablica[cel_rzad][cel_kolumna] != '-') {
        return false;  // dobry pionek i ruch uwu?
    }

    // Sprawdzmy czy mozesz to zrobic w zaleznosci od twojej rasy (nie jestem rasista)
    if (gracz == 'B' && cel_rzad == start_rzad - 1 && (cel_kolumna == start_kolumna - 1 || cel_kolumna == start_kolumna + 1)) {
        return true;  // dozwolony ruch dla gracza Bialego
    }
    else if (gracz == 'C' && cel_rzad == start_rzad + 1 && (cel_kolumna == start_kolumna - 1 || cel_kolumna == start_kolumna + 1)) {
        return true;  // dozwolony ruch dla gracza Czarnuszki
    }

    return false;  // jak nie to nie i tyle
}

int main() {
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

    while (true) {
        int start_rzad, start_kolumna;
        char kierunek;

        // Wyświetl planszę przed ruchem bialsa (taki raper)
        wyswietl_plansze(tablica);

        // Bialas podaje współrzędne i kierunek poruszenia
        cout << "Gracz B, podaj wspolrzedne pionka (rzad kolumna): ";
        cin >> start_rzad >> start_kolumna;

        cout << "Podaj kierunek poruszenia (R - prawo, L - lewo): ";
        cin >> kierunek;

        // Przesuń pionka Białasa zgodnie z wprowadzonym kierunkiem
        int cel_rzad, cel_kolumna;

        if (kierunek == 'R' && start_kolumna < 7) {
            cel_rzad = start_rzad - 1;
            cel_kolumna = start_kolumna + 1;
        }
        else if (kierunek == 'L' && start_kolumna > 0) {
            cel_rzad = start_rzad - 1;
            cel_kolumna = start_kolumna - 1;
        }
        else {
            cout << "Nieprawidlowy kierunek" << endl;
            continue;
        }

        if (czy_ruch_dozwolony('B', start_rzad, start_kolumna, cel_rzad, cel_kolumna, tablica)) {
            tablica[start_rzad][start_kolumna] = '-';
            tablica[cel_rzad][cel_kolumna] = 'B';

            // Wyświetl planszę po ruchu gracza Bialasa
            wyswietl_plansze(tablica);
        }
        else {
            cout << "Nieprawidlowy ruch gracza B." << endl;
            continue;
        }

        // Gracz Czarny wykonuje ruch
        int start_rzad_c, start_kolumna_c;
        char kierunek_c;

        cout << "Gracz C, podaj wspolrzedne pionka (rzad kolumna): ";
        cin >> start_rzad_c >> start_kolumna_c;

        cout << "Podaj kierunek poruszenia w (R - prawo, L - lewo): ";
        cin >> kierunek_c;

        // Przesuń pionka Czarnych zgodnie z wprowadzonymi współrzędnymi i kierunkiem
        int cel_rzad_c, cel_kolumna_c;

        if (kierunek_c == 'R' && start_kolumna_c < 7) {
            cel_rzad_c = start_rzad_c + 1;
            cel_kolumna_c = start_kolumna_c + 1;
        }
        else if (kierunek_c == 'L' && start_kolumna_c > 0) {
            cel_rzad_c = start_rzad_c + 1;
            cel_kolumna_c = start_kolumna_c - 1;
        }
        else {
            cout << "Nieprawidlowy kierunek poruszenia." << endl;
            continue;
        }

        if (czy_ruch_dozwolony('C', start_rzad_c, start_kolumna_c, cel_rzad_c, cel_kolumna_c, tablica)) {
            tablica[start_rzad_c][start_kolumna_c] = '-';
            tablica[cel_rzad_c][cel_kolumna_c] = 'C';

            // Wyświetl planszę po ruchu gracza Czarnych
            wyswietl_plansze(tablica);
        }
        else {
            cout << "Nieprawidlowy ruch gracza Czarnych." << endl;
            continue;
        }
    }

    return 0;
}
