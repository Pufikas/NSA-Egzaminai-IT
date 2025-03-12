#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void load(int& a, int& b, int& c, int**& skaiciai);
void sesioliktainis(int& a, int& b, int& c, int**& skaiciai, string* results);
void save(int& a, int& b, int& c, string* results);

int main() {
    int a, b, c;
    int** skaiciai = nullptr; // 2d array

    load(a, b, c, skaiciai);

    // create dynamic array to store results
    string* results = new string[c];
    sesioliktainis(a, b, c, skaiciai, results);
    save(a, b, c, results);

    // delete all dynamically allocated memory
    for (int i = 0; i < c; i++) {
        delete[] skaiciai[i]; // each row
    }
    delete[] skaiciai; // row pointers
    delete[] results; // results array

    return 0;
}

void save(int& a, int& b, int& c, string* results) {
    ofstream fout("u1res.txt");

    for (int i = 0; i < c; i++) {
        fout << results[i];
        if ((i + 1) % b == 0) {
            fout << endl;
        } else {
            fout << ";";
        }
    }
}

void sesioliktainis(int& a, int& b, int& c, int**& skaiciai, string* results) {
    for (int i = 0; i < c; i++) {
        string res = "";
        for (int j = 0; j < 3; j++) {
            int sk = skaiciai[i][j];
            // if < 10 add 0, else map it to a letter accordingly
            char first = (sk / 16 < 10) ? ('0' + sk / 16) : ('A' + sk / 16 - 10);
            char second = (sk % 16 < 10) ? ('0' + sk % 16) : ('A' + sk % 16 - 10);

            res += first;
            res += second;
        }
        results[i] = res;
    }
}

void load(int& a, int& b, int& c, int**& skaiciai) {
    ifstream fin("u1.txt");

    fin >> a >> b;
    c = a * b;

    skaiciai = new int*[c]; // allocate rows
    for (int i = 0; i < c; i++) {
        skaiciai[i] = new int[3]; // allocate columns
        fin >> skaiciai[i][0] >> skaiciai[i][1] >> skaiciai[i][2];
    }
}