#include <fstream>
#include <iostream>

using namespace std;

struct Sportininkas {
    string vardas;
    int startoNr;
    int startoLaikas;
    char lytis;
};

void skaityti(int& n, Sportininkas data[]) {
    ifstream fin("u2.txt");
    int nr, sH = 0, sM = 0, sS = 0; // starto valandos, minutes, sekundes
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> ws;
        char laikinas[21];
        fin.get(laikinas, 21);
        data[i].vardas = laikinas;
        fin >> nr;
        data[i].startoNr = nr;
        fin >> sH >> sM >> sS;
        data[i].startoLaikas = sH*3600 + sM*60 + sS;
    }

    fin >> m;

    for (int i = 0; i < m; i++) {
        fin >> startoNr;
        fin >> sH >> sM >> sS;
        // for (int j = 0; j < 4; j++) {
        //     fin >> taiklusSuviai;
        // }
    }

    fin.close();
}

int main() {
    Sportininkas data[20];
    int n;

    skaityti(n, data);

    for (int i = 0; i < n; i++) {
        cout << data[i].vardas << " " << data[i].startoNr << " " << data[i].startoLaikas << endl;
    }

    return 0;
}