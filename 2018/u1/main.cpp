#include <iostream>
#include <fstream>

using namespace std;



void skaiciavimai(int spalvos[3], int& veliavuKiekis) {
    int maz = spalvos[0];

    if (spalvos[1] < maz) { // tikrinam ar antra veliava turi maziau nei pirmoji
        maz = spalvos[1];
    } else {
        maz = spalvos[2]; // trecia veliava turi maziausiai juostu
    }
    
    veliavuKiekis = maz / 2;
    for (int i = 0; i < 3; i++) {
        spalvos[i] -= veliavuKiekis * 2;
    }
}

void saugoti(int spalvos[3], int& veliavuKiekis) {
    ofstream fout("u1res.txt");

    fout << veliavuKiekis << endl;
    fout << "G = " << spalvos[0] << endl;
    fout << "Z = " << spalvos[1] << endl;
    fout << "R = " << spalvos[2] << endl;
    
    fout.close();
}


void skaityti(int& n, int spalvos[3]) {
    ifstream fin("u1.txt");
    char spalva;
    int kiek;

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> spalva >> kiek;

        if (spalva == 'G') {
            spalvos[0] += kiek;
        } else if (spalva == 'Z') {
            spalvos[1] += kiek;
        } else {
            spalvos[2] += kiek;
        }
    }
    fin.close();
}

int main() {
    int spalvos[3] = {0}; // GZR spalvos
    int n, veliavuKiekis = 0;

    skaityti(n, spalvos);
    skaiciavimai(spalvos, veliavuKiekis);
    saugoti(spalvos, veliavuKiekis);

    return 0;
}
