#include <fstream>
#include <iostream>

using namespace std;

int menuoIDiena(int menuo, int diena) {
    if (menuo == 6) return diena;
    if (menuo == 7) return 30 + diena;
    if (menuo == 8) return 61 + diena;

    return -1; // klaida
}

int vertimasIMenesi(int diena) {
    if (diena > 30) return 7;
    if (diena > 61) return 8;

    return 6;
}

int vertimasIDienas(int diena) {
    if (diena > 30) return diena % 30;
    if (diena > 61) return diena % 61;

    return diena;
}

int didzPrad(int Zydi[]) {
    int didz = -1;
    int didzNr = -1;

    for (int i = 1; i <= 92; i++) {
        if (Zydi[i] > didz) {
            didz = Zydi[i];
            didzNr = i;
        }
    }
    return didzNr;
}

int didzPab(int Zydi[], int daugiausiaZydi) {
    int didzNr = -1;

    for (int i = 1; i <= 92; i++) {
        if (Zydi[i] == daugiausiaZydi) {
            didzNr = i;
        }
    }
    return didzNr;
}

void skaityti(int &n, int Zydi[]) {
    int nr, menPrad, dienPrad, menPab, dienPab;
    ifstream fin("u1.txt");

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> nr >> menPrad >> dienPrad >> menPab >> dienPab;
        for (int j = menuoIDiena(menPrad, dienPrad); j <= menuoIDiena(menPab, dienPab); j++) {
            Zydi[j]++;
        }
    }

    fin.close();
}

void rasyti(int daugiausiaZydi, int pradziosDiena, int pabaigosDiena) {
    ofstream fout("U1rez.txt");

    fout << daugiausiaZydi << endl;

    int pradMen = vertimasIMenesi(pradziosDiena);
    int pradDien = vertimasIDienas(pradziosDiena);
    fout << pradMen << " " << pradziosDiena << endl;

    int pabMen = vertimasIMenesi(pabaigosDiena);
    int pabDien = vertimasIDienas(pabaigosDiena);
    fout << pabMen << " " << pabaigosDiena << endl;

    fout.close();
}

int main() {
    int n;
    int Zydi[93] = {0};

    skaityti(n, Zydi);

    int daugiausiaZydi = -1;
    for (int i = 1; i <= 92; i++) {
        if (Zydi[i] > daugiausiaZydi) daugiausiaZydi = Zydi[i];
    }

    int pradziosDiena = didzPrad(Zydi);
    int pabaigosDiena = didzPab(Zydi, daugiausiaZydi);

    rasyti(daugiausiaZydi, pradziosDiena, pabaigosDiena);

    return 0;
}