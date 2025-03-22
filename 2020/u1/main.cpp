#include <fstream>

using namespace std;

int menuoIDiena(int menuo, int diena) {
    if (menuo == 6) return diena;
    if (menuo == 7) return 30 + diena;
    if (menuo == 8) return 61 + diena;

    return -1; // klaida
}

int vertimasIMenesi(int diena) {
    if (diena <= 30) return 6;
    if (diena <= 61) return 7;

    return 8;
}

int vertimasIDienas(int diena) {
    if (diena <= 30) return diena;
    if (diena <= 61) return diena - 30;

    return diena;
}

// randa pirma diena kai zydi daugiausia geliu
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

// paskutine diena kai zydi daugiausia geliu
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
    fout << pradMen << " " << pradDien << endl;

    int pabMen = vertimasIMenesi(pabaigosDiena);
    int pabDien = vertimasIDienas(pabaigosDiena);
    fout << pabMen << " " << pabDien << endl;

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

    rasyti(daugiausiaZydi, didzPrad(Zydi), didzPab(Zydi, daugiausiaZydi));

    return 0;
}