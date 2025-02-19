#include <fstream>

using namespace std;


void load(const char* path, int& n, int& k);

int main() {
    int n, k;

    load("u2.txt", n, k);
}

void load(const char* path, int& n, int& k) {
    fstream fin(path);

    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin.ignore(256);
        fin.getline();
        cout << fin.getline() << endl; 
    }
}

// void save() {
//     //
// }