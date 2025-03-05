#include <iostream>
#include <fstream>


using namespace std;


struct Avis {
    string vardas;
    string DNR;
    int DNRKoef = 0;
};

void load(const char* path, int& n, int& m, int& k, Avis*& data);
void calculate(int& n, int& m, int& k, Avis*& data);
void save(const char* path, int& n, int& m, int& k, Avis*& data);

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


void rikiuoti() // ...

void save(const char* path, int& n, int& m, int& k, Avis*& data) {
    ofstream fout(path);

    fout << data[k-1].vardas << endl;

    for (int i = 0; i < n; i++) {
        if ((k-1) == i) continue;
        data[i].vardas[0] = toupper(data[i].vardas[0]); // pirmose 10 pozicijų – avies vardas (pirmoji raidė – didžioji);
        fout << setw(10) << left << data[i].vardas << " " << data[i].DNRKoef << endl;
    }

    fout.close();
}

void calculate(int& n, int& m, int& k, Avis*& data) {
    int mainSubj = k - 1; // cuz i starts from 0 in our case
    for (int i = 0; i < n; i++) {
        data[i].DNRKoef = 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == mainSubj) continue;
        
        for (int pos = 0; pos < m; pos++) { // loop through each char
            if (data[mainSubj].DNR[pos] == data[i].DNR[pos]) {
                data[i].DNRKoef++;
            }
        }
    }

    //cout << data[1].DNRKoef << endl;
}

void load(const char* path, int& n, int& m, int& k, Avis*& data) {
    fstream fin(path);

    fin >> n >> m;
    fin >> k;

    data = new Avis[n];
    
    for (int i = 0; i < n; i++) {
        fin >> data[i].vardas >> data[i].DNR;    
        //cout << data[i] << " " << endl;
    }

    

    fin.close();
}