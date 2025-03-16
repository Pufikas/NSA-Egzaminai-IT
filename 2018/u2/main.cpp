#include <fstream>

using namespace std;

struct Slidininkas {
    string vardas;
    int laikas;
    int finisas;
};

void saugoti(int& n, int& m, Slidininkas S[], Slidininkas F[]) {
    ofstream fout("u2res.txt");

    for (int i = 0; i < m; i++) {
        fout << F[i].vardas << " " << F[i].finisas / 60 << " " << F[i].finisas % 60 << endl;
    }

    fout.close();
}

void rikiuoti(int& n, int& m, Slidininkas S[], Slidininkas F[]) {
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            if (F[i].finisas > F[j].finisas || (F[i].finisas == F[j].finisas && F[i].vardas > F[j].vardas)) {
                swap(F[i], F[j]);
            }
        }
    }
}

void skaiciuoti(int& n, int& m, Slidininkas S[], Slidininkas F[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (S[i].vardas == F[j].vardas) {
                F[j].finisas = F[j].laikas - S[i].laikas;
                break;
            }
        }
    }
}

void skaityti(int& n, int& m, Slidininkas S[], Slidininkas F[]) {
    ifstream fin("u2.txt");
    int h, min, s;

    fin >> n;
    char laikinas[21]; // vardas
    
    for (int i = 0; i < n; i++) {
        fin >> ws;
        fin.get(laikinas, 21);
        S[i].vardas = laikinas;
        fin >> h >> min >> s;
        S[i].laikas = h*3600 + min*60 + s;
    }

    fin >> m;
    for (int i = 0; i < m; i++) {
        fin >> ws;
        fin.get(laikinas, 21);
        F[i].vardas = laikinas;
        fin >> h >> min >> s;
        F[i].laikas = h*3600 + min*60 + s;
    }

    fin.close();
}

int main() {
    Slidininkas S[30]; // startavusiu slidininkai
    Slidininkas F[30]; // finiso
    int n, m;

    skaityti(n, m, S, F);
    skaiciuoti(n, m, S, F);
    rikiuoti(n, m, S, F);
    saugoti(n, m, S, F);

    return 0;
}