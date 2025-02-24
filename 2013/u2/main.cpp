#include <fstream>
#include <iostream>

#define MAX_CITIES 103
#define MAX_POPULATION 600000

using namespace std;

struct City {
    string name;
    string county;
    int population;
};

void load(const char* path, City data[], int& k, int& n);

int main() {
    City data[MAX_CITIES];
    int k, n;

    load("u2.txt", data, k, n);
}

void load(const char* path, City data[], int& k, int& n) {
    // k -> 20, n -> 13
    fstream fin(path);

    fin >> k;

    for (int i = 0; i < k; i++) {
        char cityBuffer[21]; // 20 + null terminator
        fin.read(cityBuffer, 20);
        cityBuffer[20] = '\0';
        data[i].name = cityBuffer;

        char countyBuffer[14]; // 13 + null
        fin.read(countyBuffer, 13);
        countyBuffer[13] = '\0';
        data[i].county = countyBuffer;


        fin >> data[i].population;

    }
    cout << data[2].name << " " << data[2].county << " " << data[2].population << endl;
    fin.close();
}