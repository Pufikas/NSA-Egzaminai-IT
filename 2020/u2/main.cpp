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

void skaityti(int &n, int &k, Zvejys Z[], Zuvis T[]) {
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

// zuvu mases skaiciavimas
void skaiciavimas2(int &n, int &k, Zvejys Z[], Zuvis T[]) {
    for (int i = 0; i < k; i++) { // zuvu vertinimo sarasas
        for (int j = 0; j < n; j++) { // zveju sarasas
            for (int x = 0; x < Z[i].kiekis; x++) { // zveju zuvys
                if (T[i].pav == Z[j].zuviesPav[x]) {
                    T[i].masesSuma += Z[j].zuviesMase[x];
                }
            }
        }
    }
}


// zuvu tasku skaiciavimas
void skaiciavimas(int &n, int &k, Zvejys Z[], Zuvis T[]) {
    for (int i = 0; i < n; i++) { // zvejai
        for (int j = 0; j < Z[i].kiekis; j++) { // zuvu vertinimo sarasas
            for (int x = 0; x < k; x++) { // zvejo pagautu zuvu sararas
                if (T[x].pav == Z[i].zuviesPav[j]) {
                    //cout << T[i].pav << " " << T[x].pav << " " << T[x].taskai << endl;
                
                    if (Z[i].zuviesMase[j] >= 200) {
                        Z[i].taskai += 30 + T[x].taskai;
                    } else {
                        Z[i].taskai += 10 + T[x].taskai;
                    }
                }
            }
        }
    }
}

void rikiuoti(Zuvis T[], int k) {

}

void rasyti(int &n, int &k, Zvejys Z[], Zuvis T[]) {
    ofstream fout("u2res.txt");

    fout << "Dalyviai" << endl;
    for (int i = 0; i < n; i++) {
        fout << Z[i].pav << " " << Z[i].taskai << endl;
    }

    fout << "Laimikis" << endl;
    for (int i = 0; i < k; i++) {
        fout << T[i].pav << " " << T[i].masesSuma << endl;
    }

    fout.close();
}

int main() {
    int n, k;
    Zvejys Z[31];
    Zuvis T[31];

    skaityti(n, k, Z, T);
    skaiciavimas(n, k, Z, T);
    skaiciavimas2(n, k, Z, T);
    rasyti(n, k, Z, T);
    


    return 0;
}