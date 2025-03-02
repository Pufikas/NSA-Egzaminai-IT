#include <fstream>
#include <iostream>

using namespace std;

#define MAX_MER 10
#define MAX_MOK 20


void load(const char* path, int mer, int mok, int Mokinys[MAX_MOK]);


int main() {
    int Mokinys[MAX_MOK];

    load("u1.txt", MAX_MER, MAX_MOK, Mokinys);
    for (int i = 0; i < MAX_MOK; i++) {
        cout << Mokinys[i] << " ";
    }
}

void load(const char* path, int mer, int mok, int Mokinys[MAX_MOK]) {
    fstream fin(path);

    for (int i = 0; i < mer; i++) {
        fin >> Mokinys[i];

        for (int j = mer; j < MAX_MOK; j++) {
            Mokinys[j] = 0;
        }
        
    }

    fin.close();
}