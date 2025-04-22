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

void skaiciuoti(int &d, int &dr, Dienos D[], Draugai DR[]) {
    int didz = -1;
    string diena = "";
    int aa = 0;

    for (int i = 0; i < d; i++) { // per dienas
        for (int j = 0; j < dr; j++) { // per draugus
            if (D[i].nr == DR[j].tDiena[j]) {
                for (int a = 0; a < D[i].laisvuVal; a++) {
                    if (D[i].valandos[a] == DR[j].tVal[j]) {
                        aa++;
                        diena = D[i].nr;
                        cout << DR[i].vardas << " " << D[i].valandos[a] << " " << DR[j].tVal[j] << endl;
                        //cout << aa << " " << diena << endl; 
                    }
                }
            }
        }
    }
}

int main() {
    Dienos D[7];
    Draugai DR[20];
    int d, dr;

    skaityti(d, dr, D, DR);
    skaiciuoti(d, dr, D, DR);

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