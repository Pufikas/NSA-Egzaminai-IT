#include <iostream>

using namespace std;

struct Mokinys {
    int dienos[7];
    int kl;
    int zingIlgis;
};

void skaiciuoti(Mokinys data[]) {
    ifstream fin("u1.txt");
    fin >> m;

    bool yraNulis = false;
    for (int i = 0; i < m; i++) {
        fin >> data[i].kl >> data[i].zingIlgis;
        for (int j = 0; j < 7; j++) {
            fin >> data[i].dienos[j];
        }
    }

    fin.close();
}

int main() {
    Mokinys data[50];

    skaiciuoti(data);

    return 0;
}