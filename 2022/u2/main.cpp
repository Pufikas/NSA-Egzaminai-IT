#include <fstream>
#include <iostream>

using namespace std;

struct Pratimas {
    int k; // pratimu kiekis
    string pav[8];
    string laikas[8];
    int atl[8]; // atliktu pratimu kiekis
};

struct Dienos {
    int pratPav[8];
    int diena[8];
    int uzgaista[8];
    int suma[8];
};

void grupuoti() {
    for (int i = 0; i < d; i++) {
        bool rastas = false;
        for (int j = 0; j < P[i].k; j++) {
            if (!rastas) {
                D[i].pratPav[j] = P[i].pratPav[j];
                D[i].diena[j] = P[i].diena[j];
                D[i].diena[j] = P[i].diena[j];

            }

            if ((D[i].pratPav[j] && D[i].diena[j]) != (P[i].pratPav[j] && P[i].diena[j])) {

            }
        }
    }
}

void skaityti(int &d, Pratimas P[]) {
    ifstream fin("u2.txt");

    fin >> d;
    for (int i = 0; i < d; i++) {
        fin >> P[i].k;
        char laikinas[15];
        for (int j = 0; j < P[i].k; j++) {
            fin >> ws;
            fin.get(laikinas, 15);
            P[i].pav[j] = laikinas;

            fin >> ws;
            fin.get(laikinas, 8);
            P[i].laikas[j] = laikinas;

            fin >> P[i].atl[j];
        }
    }

    fin.close();
}



int main() {
    int d;
    Pratimas P[30];

    skaityti(d, P);

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < P[i].k; j++) {
            cout << P[i].k << " " << P[i].pav[j] << " " << P[i].laikas[j] << " " << P[i].atl[j] << endl;

        }
    }

    return 0;
}