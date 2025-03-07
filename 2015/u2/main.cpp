#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct Avis {
    string vardas;
    string DNR;
    int DNRKoef;
};

void load(const char* path, int& n, int& m, int& k, Avis*& data);
void calculate(int& n, int& m, int& k, Avis*& data);
void save(const char* path, int& n, int& m, int& k, Avis*& data);
void rikiuoti(int& n, Avis*& data);

int main() {
    int n, m, k; // n -> aviu skaicius, m -> DNR fragmento ilgis, k -> tiriamosios eiles nr
    Avis* data = nullptr;
    load("u2.txt", n, m, k, data);
    calculate(n, m, k, data);
    save("u2res.txt", n, m, k, data);
    for (int i = 0; i < n; i++) {
        cout << data[i].vardas << " " << data[i].DNR << " " << data[i].DNRKoef << endl;
    }

    delete[] data;
    return 0;
}


void rikiuoti(int& n, Avis*& data) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[i].DNRKoef < data[j].DNRKoef || 
                (data[i].DNRKoef == data[j].DNRKoef && data[i].vardas > data[j].vardas)) {
                swap(data[i], data[j]);
            }
        }
    }
}

void save(const char* path, int& n, int& m, int& k, Avis*& data) {
    ofstream fout(path);

    Avis refSheep = data[k]; // remember our main sheep

    rikiuoti(n, data);
    
    fout << refSheep.vardas << endl;

    for (int i = 0; i < n; i++) { // stop at the last entry
        if (data[i].vardas == refSheep.vardas) continue;
        //data[i].vardas[0] = toupper(data[i].vardas[0]); // pirmose 10 pozicijų – avies vardas (pirmoji raidė – didžioji);
        
        fout << setw(10) << left << data[i].vardas << " " << data[i].DNRKoef << endl;
    }

    fout.close();
}

void calculate(int& n, int& m, int& k, Avis*& data) {
    for (int i = 0; i < n; i++) {
        data[i].DNRKoef = 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        
        for (int pos = 0; pos < m; pos++) { // loop through each char
            if (data[k].DNR[pos] == data[i].DNR[pos]) {
                data[i].DNRKoef++;
            }
        }
    }
}

void load(const char* path, int& n, int& m, int& k, Avis*& data) {
    fstream fin(path);

    fin >> n >> m;
    fin >> k;

    k = k - 1; // cuz our data starts from 0
    data = new Avis[n];
    
    for (int i = 0; i < n; i++) {
        fin >> data[i].vardas >> data[i].DNR;    
        //cout << data[i] << " " << endl;
    }

    

    fin.close();
}