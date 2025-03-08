#include <fstream>
#include <iostream>

using namespace std;

void load(const char* path, int& x, int& a);
void rastiSunkiausia(int& a, int& didz);
void legvesnios(int& a, int& didz, int& kartu);

int main() {
    int x, a;

    load("u1.txt", x, a);
}

void rastiSunkiausia(int& a, int& didz) {
    if (a > didz) didz = a;
}

void legvesnios(int& a, int& didz, int& kartu) {
    if ((a*2) <= didz) kartu++;
}

void load(const char* path, int& x, int& a) {
    ifstream fin(path);
    ofstream fout("u1res.txt");
    int kartu = 0;
    int didz = -1;

    fin >> x;
    for (int i = 0; i < x; i++) {
        fin >> a;
        rastiSunkiausia(a, didz);
    }

    fin.clear();
    fin.seekg(0, ios::beg); // start reading file from the start

    fin >> x;
    for (int i = 0; i < x; i++) {
        fin >> a;
        legvesnios(a, didz, kartu);
    }

    fout << didz << " " << kartu;
}