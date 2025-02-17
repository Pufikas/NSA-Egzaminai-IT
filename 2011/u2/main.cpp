#include <fstream>
#include <iostream>


using namespace std;

struct Pair {
    string name;
    int points[2][100];
    int score = 0;
};

void load(const char* path, Pair data[], int& n, int& k);
void save(Pair data[], int& n);
void sort(Pair data[], int& n, int& k);
void calculate(Pair data[], int& n, int& k);

int main() {
    Pair data[100];
    int n, k; // pairs, voters

    load("u2.txt", data, n, k);
    calculate(data, n, k);
    sort(data, n, k);
    save(data, n);
}


void save(Pair data[], int& n) {
    ofstream fout("u2res.txt");

    for (int i = 0; i < n; i++) {
        fout << data[i].name << " " << data[i].score << endl;
    }

    fout.close();
}

void sort(Pair data[], int& n, int& k) {
    Pair temp;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[i].score < data[j].score) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}


void calculate(Pair data[], int& n, int& k) {
    for (int i = 0; i < n; i++) {
        int tMin = INT_MAX, tMax = INT_MIN;
        int aMin = INT_MAX, aMax = INT_MIN;
        int tSum = 0, aSum = 0;

        // technika
        for (int x = 0; x < k; x++) {
            int score = data[i].points[0][x];
            if (score < tMin) tMin = score;
            if (score > tMax) tMax = score;
            tSum += score;
        }

        // artiskumas
        for (int y = 0; y < k; y++) {
            int score = data[i].points[1][y];
            if (score < aMin) aMin = score;
            if (score > aMax) aMax = score;
            aSum += score;
        }

        int tRes = tSum - tMin - tMax;
        int aRes = aSum - aMin - aMax;

        data[i].score = tRes + aRes;
    }
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
            }
        }
    }
    fin.close();
}
