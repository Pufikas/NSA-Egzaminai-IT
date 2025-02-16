#include <fstream>
#include <iostream>


using namespace std;

struct Pair {
    string name;
    int points[2][100];
    int score = 0;
};

void load(const char* path, Pair data[], int& n, int& k);

int main() {
    Pair data[100];
    int n, k; // pairs, voters

    load("u2.txt", data, n, k);
}

void load(const char* path, Pair data[], int& n, int& k) {
    fstream fin(path);

    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin.ignore();
        getline(fin, data[i].name);

        for (int j = 0; j < 2; j++) {
            for (int x = 0; x < k; x++) {
                fin >> data[i].points[j][x];
                cout << data[i].points[j][x] << " ";
            }
        }
    }

    fin.close();

}
