#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("Rezultatai.txt");

struct DiskoMetejai {
    string vardas;
    double res;
};

void skaitytiOlimpines(DiskoMetejai D[], int &n) {
    ifstream fin("Olimpines.txt");
    
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> D[i].vardas >> D[i].res;
    }

    fin.close();
}

void skaiciuotiVidurki(DiskoMetejai D[], int &n) {
    float vid = 0;
    
    for (int i = 0; i < n; i++) {
        vid += D[i].res;
    }
 
    fout << "Vidutiniškai diskas skriejo " << vid / n << " m." << endl;
}

// n, cia atitinka metiko eiles nr
char gautiMetejoKoda(DiskoMetejai D[], int n) {
    return D[n].vardas[0];
}

int main() {
    DiskoMetejai D[32];
    int n;

    fout << "Disko metimo duomenų analizės rezultatai:" << endl << endl;
    fout << "Olimpinės žaidynės:";

    skaitytiOlimpines(D, n);
    skaiciuotiVidurki(D, n);

    cout << gautiMetejoKoda(D, 2);
    for (int i = 0; i < n; i++) {
        cout << D[i].vardas << " " << D[i].res << endl;
    }

    return 0;
}