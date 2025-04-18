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
    string slap = "";
    int panasumas = 0;
    string stiprumas;
};

void skaityti(Slaptazodis S[], Slaptazodis V[], int &n, int &s) {
    ifstream fin("u2.txt");
    
    fin >> n >> s;
    char laikinas[15];
    for (int i = 0; i < n; i++) {
        fin >> ws;
        fin.get(laikinas, 15);
        S[i].slap = laikinas;
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
        for (int j = 0; j < s; j++) {
            int pan = 0;

            pan += abs(S[i].ilgis - V[j].ilgis);
            pan += abs(S[i].didzRaides - V[j].didzRaides);
            pan += abs(S[i].mazRaides - V[j].mazRaides);
            pan += abs(S[i].skaiciuKiekis - V[j].skaiciuKiekis);
            pan += abs(S[i].specSimboliai - V[j].specSimboliai);

            PS[cc].slap = V[j].slap;
            PS[cc].panasumas = pan;
            PS[cc].stiprumas = V[j].stiprumas;
            cc++;
        }
    }
}

void rusiuoti(PanasusSlap PS[], int &cc) {
    for (int i = 0; i < cc-1; i++) {
        for (int j = i+1; j < cc-1; j++) {
            if (PS[j].panasumas < PS[i].panasumas) {
                swap(PS[i], PS[j]);
            }
        }
    }
}

// ai krc
void rasyti(Slaptazodis S[], PanasusSlap PS[], int &cc, int &n) {
    ofstream fout("u2res.txt");
    for (int i = 0; i < cc; i++) {
        fout << PS[i].slap << " " << PS[i].panasumas << endl;
    }
    fout.close();
}



int main() {
    Slaptazodis S[5];
    Slaptazodis V[25];
    PanasusSlap PS[25];
    int n, s, cc;

    skaityti(S, V, n, s);
    skaiciuoti(S, V, PS, n, s, cc);
    rusiuoti(PS, cc);
    rasyti(S, PS, cc, n);
 
    return 0;
}