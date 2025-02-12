#include <fstream>
#include <iostream>

using namespace std;

#define MOKINIAI 100


int skaiciuoti(int(&data)[MOKINIAI]) {
    static int sachmatuLenta[6] = {8, 2, 2, 2, 1, 1};

    int added[6] = {};

    for (int i = 1; i < data[0] * 6 + 1; i++) {
        added[(i-1) % 6] += data[i];
    }

    int res = INT_MAX;

    for (int i = 0; i < 6; i++) {
        int kiekis = added[i] / sachmatuLenta[i];

        if (kiekis < res) res = kiekis;
    }
    return res;
}

bool load(const char* failas, int(&data)[MOKINIAI], int& nuskaityti) {
    ifstream fin(failas);
    if (!fin.is_open()) return false;
    nuskaityti = 0;
    while (fin >> data[nuskaityti++]);
    return true;
}

bool save(const char* failas, int(&data)[MOKINIAI]) {
    ofstream fout(failas);
    if (!fout.is_open()) return false;
    fout << skaiciuoti(data);
    return true;
}


int main() {
    int data[MOKINIAI];
    int nuskaityti = 0;
    if (!load("u1.txt", data, nuskaityti)) return 1;

    for (int i = 0; i < nuskaityti; i++) {
        cout << data[i] << " ";
    }

    return !save("u1res.txt", data);
}