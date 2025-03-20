#include <fstream>
#include <iostream>

using namespace std;

struct Sportininkas {
    string vardas;
    int startoNr;
    int startoLaikas;
    int pabaigosLaikas;
    int baudosMin;
    char lytis;
};
void skaityti(int& n, int& m, Sportininkas data[], Sportininkas naujas[]) {
    ifstream fin("u2.txt");
    int nr, sH = 0, sM = 0, sS = 0; // starto valandos, minutes, sekundes
    fin >> n;
    string taikiniai;

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
        fin >> naujas[i].startoNr >> sH >> sM >> sS;
        //getline(fin, taikiniai);
        int taiklus1, taiklus2;
        fin >> taiklus1 >> taiklus2;
        naujas[i].pabaigosLaikas = sH*3600 + sM*60 + sS;
        naujas[i].baudosMin = (10 - (taiklus1 + taiklus2));

        if (taiklus1 + taiklus2 == 2) {
            naujas[i].lytis = 'M';
        } else if (taiklus1 + taiklus2 == 4) {
            naujas[i].lytis = 'V';
        }
    }

    fin.close();
}

int main() {
    Sportininkas data[20];
    Sportininkas naujas[20];
    int n, m;

    skaityti(n, m, data, naujas);

    for (int i = 0; i < n; i++) {
        cout << data[i].vardas << " " << data[i].startoNr << " " << data[i].startoLaikas << endl;
    }

    cout << endl;

    for(int i = 0; i < m; i++) {
        cout << naujas[i].lytis << " " << naujas[i].startoNr << " " << naujas[i].pabaigosLaikas / 3600 << " " << naujas[i].pabaigosLaikas % 3600 / 60 << " " << naujas[i].pabaigosLaikas % 60 << " baudos " << naujas[i].baudosMin<< endl;
    }
    return 0;
}