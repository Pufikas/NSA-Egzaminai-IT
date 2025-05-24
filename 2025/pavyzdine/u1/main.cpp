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
    }

    fin.close();
    fin2.close();
}

void vidurkisOlimpiniu(DiskoMetejai D[], int &n) {
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

void skirtumasTarpRez(DiskoMetejai D[], int &n) {
    double didz = -1;
    double maz = 999;

    // surandam didziausia ir maziausia reiskme olimpinese 
    for (int i = 0; i < n; i++) {
        if (D[i].res > didz) didz = D[i].res;
        if (D[i].res < maz) maz = D[i].res;
    }

    fout << "Skirtumas tarp didžiausio ir mažiausio rezultato " << didz - maz << " m." << endl;
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

    fout << endl;
    fout << "Seniausiai pasiektas geriausias rezultatas:" << endl;
    fout << gautiMetejoPavarde(P[indeksas].vardas) << " " << P[indeksas].res << " " << anksciausiMetai << " " << P[indeksas].valstybe << endl << endl;
}

void sportininkuSkirtumai(DiskoMetejai D[], DiskoMetejai S[], Pasiekimai P[], int &n) {
    double res = 0;

    for (int i = 0; i < n; i++) {
        S[i].res = P[i].res - D[i].res;
        S[i].vardas = D[i].vardas;
    }

    // rusiuoti
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (S[i].res > S[j].res) {
                swap(S[i], S[j]);
            }
        }
    }

    // rasymas i faila
    fout << "Skirtumas tarp sportininkų pasiekimų:" << endl;
    for (int a = 0; a < n; a++) {
        fout << gautiMetejoPavarde(S[a].vardas) << " " << S[a].res << " m" << endl;
    }
}

void vidurkisPasiekimu(DiskoMetejai D[], Pasiekimai P[], int &n) {
    float sumaOlimp = 0;
    float sumaPasie = 0;
    float suma = 0;

    for (int i = 0; i < n; i++) {
        sumaOlimp += D[i].res;
        sumaPasie += P[i].res;
    }
    suma = (sumaPasie - sumaOlimp) / n;

    fout << "Vidutiniškai diskas skriejo " << sumaPasie / n << " m." << endl; 
    fout << "Vidurkis " << suma << " m didesnis negu olimpinėse žaidynėse." << endl;
}

int main() {
    DiskoMetejai D[32];
    DiskoMetejai S[32]; // del 9 uzd
    Pasiekimai P[32];
    int n;

    fout << "Disko metimo duomenų analizės rezultatai:" << endl << endl;
    fout << "Olimpinės žaidynės:" << endl;

    skaitytiFailus(D, P, n);
    vidurkisOlimpiniu(D, n);
    skirtumasTarpRez(D, n);

    fout << endl;
    fout << "Geriausi rezultatai:" << endl;
    
    vidurkisPasiekimu(D, P, n);
    anksGeriausiasRez(D, P, n);
    sportininkuSkirtumai(D, S, P, n);


    return 0;
}