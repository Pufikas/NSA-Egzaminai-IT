#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Slaptazodis {
    string slap;
    int ilgis;
    int mazRaides;
    int skaiciuKiekis;
    int specSimboliai;
    string stiprumas;
};

void skaityti(Slaptazodis S[], Slaptazodis V[], int &n, int &s) {
    ifstream fin("u2.txt");
    
    fin >> n >> s;
    fin.ignore();
    
    for (int i = 0; i < n; i++) {
        fin >> ws;
        getline(fin, S[i].slap, ' ');
        fin >> S[i].ilgis >> S[i].mazRaides >> S[i].skaiciuKiekis >> S[i].specSimboliai;
        fin.ignore();
    }
    
    for (int i = 0; i < s; i++) {
        fin >> ws;
        getline(fin, V[i].slap, ' ');
        
        fin >> V[i].ilgis >> V[i].mazRaides >> V[i].skaiciuKiekis >> V[i].specSimboliai;
        
        string temp;
        fin >> temp;
        V[i].stiprumas = temp;
        fin.ignore();
    }
    
    fin.close();
}

int main() {
    Slaptazodis S[5];
    Slaptazodis V[25];
    int n, s;

    skaityti(S, V, n, s);

 
    for (int i = 0; i < s; i++) {
        cout << V[i].slap << " " 
             << V[i].ilgis << " " << V[i].mazRaides << " "
             << V[i].skaiciuKiekis << " " << V[i].specSimboliai << " " << endl;
    }

    return 0;
}