#include <fstream>
#include <iostream>

using namespace std;

int Pratimas {
    int k; // pratimu kiekis
    string pav;
    string laikPav;
    int atl; // atliktu pratimu kiekis
};

void skaityti(Pratimas P[]) {
    ifstream fin("u2.txt");

    fin >> d;
    for (int i = 0; i < d; i++) {
        fin >> P[i].k;
        char laikinas[15];
        for (int j = 0; j < P[i].k; j++) {
            fin >> ws;
            fin.get(laikinas, 15);
            P[i].pav = laikinas;

            fin >> ws;
            fin.get(laikinas, 8);
            P[i].laikPav = laikinas;

            fin >> P[i].atl;
        }
    }

    fin.close();
}

int main() {
    int d;

    return 0;
}