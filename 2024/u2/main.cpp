#include <fstream>
#include <iostream>

using namespace std;

const int MAX_VAL = 48;

struct Dienos {
    string nr;
    int laisvuVal;
    int valandos[MAX_VAL];
};

struct Draugai {
    string vardas;
    int isv; // isviso laiku tinka
    string tDiena[MAX_VAL]; // tinka diena
    int tVal[MAX_VAL];
};

struct Rezultatai {
    string diena;
    int valanda;
    int kiekis;
    string draugai[20];
};


void skaityti(int &d, int &dr, Dienos D[], Draugai DR[]) {
    ifstream fin("u2.txt");

    fin >> d >> dr;
    
    // laikai
    for (int i = 0; i < d; i++) {
        fin >> D[i].nr >> D[i].laisvuVal;
        for (int j = 0; j < D[i].laisvuVal; j++) {
            fin >> D[i].valandos[j];
        }
    }

    // dr laikai
    for (int i = 0; i < dr; i++) {
        char laikinas[13];
        fin >> ws;
        fin.get(laikinas, 13);
        DR[i].vardas = laikinas;

        fin >> DR[i].isv;
        for (int j = 0; j < DR[i].isv; j++) {
            fin >> DR[i].tDiena[j] >> DR[i].tVal[j];
        }
    }

    fin.close();
}

void skaiciuoti(int &d, int &dr, int &isv, Dienos D[], Draugai DR[], Rezultatai R[]) {
    string drg[20];

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < D[i].laisvuVal; j++) {
            int kiek = 0;

            // kiek draugu tinka i laika
            for (int k = 0; k < dr; k++) {
                for (int l = 0; l < DR[k].isv; l++) {
                    if (D[i].nr == DR[k].tDiena[l] && D[i].valandos[j] == DR[k].tVal[l]) {
                        drg[kiek] = DR[k].vardas;
                        kiek++;
                        break;
                    }
                }
            }

            if (kiek >= 4) { // turi buti maziau nei keturi draugai (pagal uzduoti)
                R[isv].diena = D[i].nr;
                R[isv].valanda = D[i].valandos[j];
                R[isv].kiekis = kiek;

                for (int m = 0; m < kiek; m++) {
                    R[isv].draugai[m] = drg[m];
                }
                isv++;
            }

            
        }
    }
}

void rusiuoti(int &isv, Rezultatai R[]) {
    for (int i = 0; i < isv; i++) {
        for (int j = i+1; j < isv; j++) {
            if (R[i].kiekis < R[j].kiekis) swap(R[i], R[j]);
        }
    }
}

void rasyti(int &isv, Rezultatai R[]) {
    ofstream fout("U2rez.txt");


    for (int i = 0; i < isv; i++) {
        fout << R[i].diena << " " << R[i].valanda << " " << R[i].kiekis << endl;
        for (int j = 0; j < R[i].kiekis; j++) {
            fout << R[i].draugai[j] << endl;
        }
    }

    

    fout.close();
}

int main() {
    Dienos D[7];
    Draugai DR[20];
    Rezultatai R[20];
    int d, dr, isv = 0;

    skaityti(d, dr, D, DR);
    skaiciuoti(d, dr, isv, D, DR, R);
    rusiuoti(isv, R);
    rasyti(isv, R);

    // cout << d << " " << dr << endl;
    // for (int i = 0; i < d; i++) {
    //     cout << D[i].nr << " " << D[i].laisvuVal << " ";
    //     for (int j = 0; j < D[i].laisvuVal; j++) {
    //         cout << D[i].valandos[j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dr << endl;
    for (int i = 0; i < dr; i++) {
        cout << DR[i].vardas << " ";
        for (int j = 0; j < DR[i].isv; j++) {
            cout << " " << DR[i].tDiena[j] << " " << DR[i].tVal[j];
        }
        cout << endl;
    }

    return 0;
}