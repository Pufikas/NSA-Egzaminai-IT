#include <iostream>
#include <fstream>

using namespace std;

struct Mokinys {
    int dienos[7];
    int kl = 0;
    int zingIlgis = 0;
    bool visiDuomenys = true;
};

struct Klase {
    int mokIvede = 0;
    int kl = 0;
    double sumaKM = 0.0;
};

void skaiciuoti(Mokinys data[], Klase Klases[], int &m, int &klasiuKiekis) {
    ifstream fin("u1.txt");
    fin >> m;

    // raso duomenys
    for (int i = 0; i < m; i++) {
        fin >> data[i].kl >> data[i].zingIlgis;
        for (int j = 0; j < 7; j++) {
            fin >> data[i].dienos[j];
            if (data[i].dienos[j] == 0) {
                data[i].visiDuomenys = false;
            }
        }
    }

    // raso unikales klases
    bool unikalesKlases[13] = {false};
    klasiuKiekis = 0;

    for (int i = 0; i < m; i++) {
        if (data[i].visiDuomenys && !unikalesKlases[data[i].kl]) {
            unikalesKlases[data[i].kl] = true;
            Klases[klasiuKiekis].kl = data[i].kl;
            klasiuKiekis++;
        }
    }

    // skaiciuoja kiekvienai klasei zingsnius

    for (int i = 0; i < klasiuKiekis; i++) {
        for (int j = 0; j < m; j++) {
            if (data[j].kl == Klases[i].kl && data[j].visiDuomenys) {
                Klases[i].mokIvede++;

                int suma = 0;
                for (int k = 0; k < 7; k++) {
                    suma += data[j].dienos[k];
                }

                Klases[i].sumaKM += (data[j].zingIlgis * suma) / 100000.0;
            }
        }
    }

    fin.close();
}

int main() {
    Mokinys data[50];
    Klase Klases[12];
    ofstream fout("u1res.txt");
    int m, klasiuKiekis;

    skaiciuoti(data, Klases, m, klasiuKiekis);

    for (int i = 0; i < klasiuKiekis; i++) {
        fout << Klases[i].kl << " " << Klases[i].mokIvede << " ";
        fout.precision(2);
        fout << fixed << Klases[i].sumaKM << endl;
    }
    fout.close();

    return 0;
}