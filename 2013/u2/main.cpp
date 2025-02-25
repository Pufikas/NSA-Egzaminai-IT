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

struct CountyStats {
    string name;
    int totalPopulation;
    int minPopulation;
};

void load(const char* path, City data[], int& k);
void calculate(City data[], int k, CountyStats counties[], int& countyCount);
void sortCounties(CountyStats counties[], int countyCount);
void save(const char* path, CountyStats counties[], int countyCount);

int main() {
    City data[MAX_CITIES];
    CountyStats counties[MAX_CITIES];
    int k, countyCount;

    load("u2.txt", data, k);
    calculate(data, k, counties, countyCount);
    sortCounties(counties, countyCount);
    save("u2res.txt", counties, countyCount);

    return 0;
}

void load(const char* path, City data[], int& k) {
    fstream fin(path);

    fin >> k;
    string line;
    getline(fin, line); // skip first line

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

        getline(fin, line); // go to the next line
    }

    fin.close();
}

void calculate(City data[], int k, CountyStats counties[], int& countyCount) {
    countyCount = 0;

    for (int i = 0; i < k; i++) {
        bool found = false;

        // check if county exists in the counties array
        for (int j = 0; j < countyCount; j++) {
            if (counties[j].name == data[i].county) {
                found = true;
                counties[j].totalPopulation += data[i].population;
                if (data[i].population < counties[j].minPopulation) {
                    counties[j].minPopulation = data[i].population;
                }
                break;
            }
        }

        // if not found add it to counties array
        if (!found) {
            counties[countyCount].name = data[i].county;
            counties[countyCount].totalPopulation = data[i].population;
            counties[countyCount].minPopulation = data[i].population;
            countyCount++;
        }
    }
}

void sortCounties(CountyStats counties[], int countyCount) {
    for (int i = 0; i < countyCount; i++) {
        for (int j = i + 1; j < countyCount; j++) {
            if (counties[i].minPopulation > counties[j].minPopulation ||
                (counties[i].minPopulation == counties[j].minPopulation && 
                counties[i].name > counties[j].name)) {
                
                CountyStats temp = counties[i];
                counties[i] = counties[j];
                counties[j] = temp;
            }
        }
    }
}

void save(const char* path, CountyStats counties[], int countyCount) {
    ofstream fout(path);

    fout << countyCount << endl;

    for (int i = 0; i < countyCount; i++) {
        fout << counties[i].name << " " << counties[i].minPopulation << " " << counties[i].totalPopulation << endl;
    }

    fout.close();
}