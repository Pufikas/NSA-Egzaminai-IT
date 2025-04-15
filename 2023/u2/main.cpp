#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Slaptazodis {
    string slap = "";
    int ilgis;
    int didzRaides;
    int mazRaides;
    int skaiciuKiekis;
    int specSimboliai;
    string stiprumas;
};

struct PanasusSlap {
    string name = "";
    int panasumas = 0;
};

void skaityti(Slaptazodis S[], Slaptazodis V[], int &n, int &s) {
    ifstream fin("u2.txt");
    
    fin >> n >> s;
    char laikinas[15];
    for (int i = 0; i < n; i++) {
        fin >> ws;
        fin.get(laikinas, 15);
        S[i].slap = laikinas;
        //cout << S[i].slap << " ";
        
        fin >> S[i].ilgis >> S[i].didzRaides >> S[i].mazRaides >> S[i].skaiciuKiekis >> S[i].specSimboliai;
    }
    
    for (int i = 0; i < s; i++) {
        fin >> ws;
        fin.get(laikinas, 15);
        V[i].slap = laikinas;
        
        fin >> V[i].ilgis >> V[i].didzRaides >> V[i].mazRaides >> V[i].skaiciuKiekis >> V[i].specSimboliai;
        
        string temp;
        fin >> temp;
        V[i].stiprumas = temp;
    }
    
    fin.close();
}

void skaiciuoti(Slaptazodis S[], Slaptazodis V[], PanasusSlap PS[], int &n, int &s, int &cc) {
    for (int i = 0; i < n; i++) {
        int panasumoReiksme = 99;
        int slapVt = -1; // slaptazodzio kuris labiausiai panasus vieta
        for (int j = 0; j < s; j++) {
            int pan = 0;

            pan += abs(S[i].ilgis - V[j].ilgis);
            pan += abs(S[i].didzRaides - V[j].didzRaides);
            pan += abs(S[i].mazRaides - V[j].mazRaides);
            pan += abs(S[i].skaiciuKiekis - V[j].skaiciuKiekis);
            pan += abs(S[i].specSimboliai - V[j].specSimboliai);

            PS[cc].slap = V[j].slap;
            PS[cc].panasumas = pan;
            cc++;
        }
    }
}

void rusiuoti(PanasusSlap PS[], int &cc) {
    for (int i = 0; i < cc-1; i++) {
        for (int j = i+1; j < cc; j++) {
            if (PS[j].panasumas < PS[i].panasumas) {
                swap(PS[i], PS[j]);
            }
        }
    }
}

void rasyti() {
    //
}

int main() {
    Slaptazodis S[5];
    Slaptazodis V[25];
    PanasusSlap PS[25];
    int n, s;

    skaityti(S, V, n, s);
    skaiciuoti(S, V, PS, n, s, cc);
    rusiuoti(PS, cc);
 
    for (int i = 0; i < s; i++) {
        cout << ps[i] << endl;
        //cout << V[i].slap << " " << V[i].ilgis << " " << V[i].didzRaides << " " << V[i].mazRaides << " " << V[i].skaiciuKiekis << " " << V[i].specSimboliai << endl;
        //cout << S[i].slap << endl;
        //cout << S[i].slap << " " 
        //     << S[i].ilgis << " " << S[i].mazRaides << " "
         //    << S[i].skaiciuKiekis << " " << S[i].specSimboliai << " " << endl;
    }

    return 0;
}