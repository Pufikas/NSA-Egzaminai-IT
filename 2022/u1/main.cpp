#include <fstream>
#include <iostream>

using namespace std;

struct Mokinys {
    string vardas;
    int taskai = 0;
    int laikas = 0;
    int teisingi = 0;
};

void skaiciavimas(int mokSk, Mokinys data[]) {
    ifstream fin("u1.txt");
    int u, laikas;

    fin >> u;
    int laikoLimitas[u] = {0}; int maksVertinimas[u] = {0};

    for (int i = 0; i < u; i++) {
        fin >> laikoLimitas[i];
    }

    for (int i = 0; i < u; i++) {
        fin >> maksVertinimas[i]; 
    }

    char laikinas[11];
    // mokiniai
    for (int i = 0; i < mokSk; i++) {
        fin >> ws;
        fin.get(laikinas, 11);
        data[i].vardas = laikinas;

        for (int j = 0; j < u; j++) {
            fin >> laikas;
            if (laikas != 0) {
                data[i].laikas += laikas;
                data[i].teisingi++;
                if (laikas <= laikoLimitas[j]) {
                    data[i].taskai += maksVertinimas[j];
                } else {
                    data[i].taskai += maksVertinimas[j] / 2;
                }
            }
        }
    }

    fin.close();

}

int main() {
    int mokSk = 5;
    int didzTaskai = 0;
    Mokinys data[mokSk];
    ofstream fout("u1res.txt");

    skaiciavimas(mokSk, data);

// sutvarkyt
    for (int i = 0; i < mokSk; i++) {
        for (int j = i+1; j < mokSk; j++) {
            if (data[i].taskai > didzTaskai) didzTaskai = data[i].taskai;
            if (data[i].taskai > data[j].taskai) {
                swap(data[i], data[j]);
            } else if ((data[i].taskai == data[j].taskai) && data[i].laikas < data[j].laikas) {
                swap(data[i], data[j]);
            }
        }
    }

    cout << didzTaskai << endl;
    for (int i = 0; i < mokSk; i++) {
        if (data[i].taskai == didzTaskai) {
            cout << data[i].vardas << " " << data[i].taskai << " " << data[i].laikas << " " << data[i].teisingi << endl;
        }
    }


    fout.close();
    return 0;
}