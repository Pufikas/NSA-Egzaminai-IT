#include <iostream>
#include <fstream>

using namespace std;

void load(const char* path, int& n, int& m, int& k, Avis data[n]);

struct Avis {
    char* vardas[10];
    char* DNR[4];
    int DNRKoef;
};

int main() {
    int n, m, k; // k -> tiriamosios eiles nr
    Avis data[n];
    load("u2.txt", n, m, k, data);
}

void load(const char* path, int& n, int& m, int& k, Avis data[n]) {
    fstream fin(path);

    fin >> n >> m;
    fin >> k;
    for (int i = 0; i < n; i++) {
        fin >> data[i].vardas >> data[i].DNR;    
        //cout << data[i] << " " << endl;
    }

    

    fin.close();
}