#include <fstream>
#include <iostream>

using namespace std;

struct Zvejys {
    string pav;
    string zuviesPav[31];
    int kiekis;
    int zuviesMase[31];
    int taskai = 0;
};

struct Zuvis {
    string pav;
    int taskai;
    int masesSuma = 0;
};

void skaityti(int &m, int &n, int &k, Zvejys Z[], Zuvis T[]) {
    ifstream fin("u2.txt");
    char laikinas[21];

    // skaitom dalyvius ir ju laimikius
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> ws;
        fin.get(laikinas, 21);
        Z[i].pav = laikinas;

        fin >> Z[i].kiekis;
        for (int j = 0; j < Z[i].kiekis; j++) {
            fin >> ws;
            fin.get(laikinas, 21);
            Z[i].zuviesPav[j] = laikinas;

            fin >> Z[i].zuviesMase[j];
        }
    }

    // skaitom zuvies vertimus
    fin >> k;
    for (int i = 0; i < k; i++) {
        fin >> ws;
        fin.get(laikinas, 21);
        T[i].pav = laikinas;
        fin >> T[i].taskai;
    }


    fin.close();
}

int main() {
    int m, n, k;
    Zvejys Z[31];
    Zuvis T[31];

    skaityti(m, n, k, Z, T);

    return 0;
}