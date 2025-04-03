#include <fstream>

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

    // suranda didziausia taskus
    for (int i = 0; i < mokSk; i++) {
        if (data[i].taskai > didzTaskai) {
            didzTaskai = data[i].taskai;
        }
    }

    // rikiuoja visus mokinius pagal taskus
    for (int i = 0; i < mokSk-1; i++) {
        for (int j = 0; j < mokSk-i-1; j++) {
            if (data[j].taskai < data[j+1].taskai)
                swap(data[j], data[j+1]);
        }
    }

    // rikiuoja tik jeigu yra lygus didzTaskai, tuomet rikiuoja pagal teisingai isprestu uzd kieki ir uzgaista laika
    for (int i = 0; i < mokSk-1; i++) {
        for (int j = 0; j < mokSk-i-1; j++) {
            if (data[j].taskai == didzTaskai && data[j+1].taskai == didzTaskai) {
                if (data[j].teisingi < data[j+1].teisingi) {
                    swap(data[j], data[j+1]);
                }
                else if (data[j].teisingi == data[j+1].teisingi && 
                        data[j].laikas > data[j+1].laikas) {
                    swap(data[j], data[j+1]);
                }
            }
        }
    }

    fout << didzTaskai << endl;
    for (int i = 0; i < mokSk; i++) {
        if (data[i].taskai == didzTaskai) {
            fout << data[i].vardas << " " << data[i].teisingi << " " << data[i].laikas << endl;
        }
    }

    fout.close();
    return 0;
}