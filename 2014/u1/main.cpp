#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int k;
}

void load(const char* path, int& k) {
    fstream fin(path);

    fin >> k;

    for (int i = 0; i < k; i++) {
        fin >> 
    }
    fin.close();
}