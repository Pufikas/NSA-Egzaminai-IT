#include <fstream>
#include <iostream>

int main() {
    int n, x, y, dx, dy, r, g ,b;

    return 0;
}

void load() {
    fstream fin("u2.txt");

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> x >> y >> dx >> dy >> r >> g >> b;
    }

    fin.close();
}

void save() {
    ofstream fout("u2res.txt");

    fout.close();
}

// skip