#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

ofstream fout("Rezultatai.txt");

struct DiskoMetejai {
    string vardas;
    double res;
};

struct Pasiekimai {
    string vardas;
    double res;
    int data;
    string valstybe;
};

void skaitytiFailus(DiskoMetejai D[], Pasiekimai P[], int &n) {
    ifstream fin("Olimpines.txt");
    ifstream fin2("Pasiekimai.csv");
    string vardas, res, data, valstybe;

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> D[i].vardas >> D[i].res;
    }

    for (int j = 0; j < n; j++) {
        string eilute;

        getline(fin2, eilute); // gauna visa pilna eilute
        istringstream ss(eilute);

        getline(ss, vardas, ';');
        getline(ss, res, ';');
        getline(ss, data, ';');
        getline(ss, valstybe, ';');

        P[j].vardas = vardas;
        P[j].res = stod(res); // stod -> float
        P[j].data = stoi(data); // stoi -> int
        P[j].valstybe = valstybe;

        //cout << vardas << " " << res << " " << data << " " << valstybe << endl;
    }

    fin.close();
    fin2.close();
}

void skaiciuotiVidurki(DiskoMetejai D[], int &n) {
    float vid = 0;
    
    for (int i = 0; i < n; i++) {
        vid += D[i].res;
    }
 
    fout << "Vidutiniškai diskas skriejo " << vid / n << " m." << endl;
}

string gautiMetejoPavarde(string kodas) {
    return kodas.substr(1); // pasalina pirma raide
    // AGUDZIUS -> GUDZIUS
}

int gautiMetus(int metai) {
    return metai / 10000;
    // 20180610 -> 2018
}

void anksGeriausiasRez(DiskoMetejai D[], Pasiekimai P[], int &n) {
    int anksciausiMetai = 9999;
    int indeksas;

    for (int i = 0; i < n; i++) { 
        if (gautiMetus(P[i].data) < anksciausiMetai) {
            anksciausiMetai = gautiMetus(P[i].data);
            indeksas = i;
        }
    }

    fout << "Seniausiai pasiektas geriausias rezultatas:" << endl;
    fout << gautiMetejoPavarde(P[indeksas].vardas) << " " << P[indeksas].res << " " << anksciausiMetai << " " << P[indeksas].valstybe << endl;
}

void skaiciuoti()

int main() {
    DiskoMetejai D[32];
    Pasiekimai P[32];
    int n;

    fout << "Disko metimo duomenų analizės rezultatai:" << endl << endl;
    fout << "Olimpinės žaidynės:" << endl;

    skaitytiFailus(D, P, n);
    skaiciuotiVidurki(D, n);
    anksGeriausiasRez(D, P, n);

   
    // for (int i = 0; i < n; i++) {
    //     cout << D[i].vardas << " " << D[i].res << endl;
    // }

    return 0;
}