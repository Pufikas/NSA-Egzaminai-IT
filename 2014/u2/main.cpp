#include <fstream>
#include <iostream>

using namespace std;

#define MAX_SEQUENCES 10
#define MAX_SEQUENCE_LENGTH 30

void load(const char* path, int startingCoords[], int goal[], int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH], int sequenceLength[], int& n);

int main() {
    int n, k;
    int startingCoords[2] = {0};
    int goal[2] = {0};
    int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH] = {0};
    int sequenceLength[MAX_SEQUENCES] = {0};

    load("u2.txt", startingCoords, goal, coords, sequenceLength, n);

    return 0;
}

void load(const char* path, int startingCoords[], int goal[], int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH], int sequenceLength[], int& n) {
    fstream fin(path);

    fin >> startingCoords[0] >> startingCoords[1];
    fin >> goal[0] >> goal[1];
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> sequenceLength[i];

        for (int j = 0; j < sequenceLength[i]; j++) {
            fin >> coords[i][j];
        }
    }

    fin.close();
}

void save(const char* path) {
    ofstream fout(path);

    fout.close();
}