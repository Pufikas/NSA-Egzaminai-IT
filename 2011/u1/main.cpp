#include <fstream>
#include <iostream>

using namespace std;

#define MAX_GLOVES 30
#define MAX_SIZE 100

struct Glove {
    int gender;
    int hand;
    int size;
};

bool load(const char* path, int& gloveCount, Glove data[]);
int countFemalePairs(const Glove data[], int gloveCount);
int countMalePairs(const Glove data[], int gloveCount);

int main() {
    Glove data[MAX_GLOVES];
    int gloveCount = 0;
    if (!load("u1.txt", gloveCount, data)) return 1;
    //return !save("u1res.txt", data);
    countFemalePairs(data, gloveCount);
    countMalePairs(data, gloveCount);
    return 0;
}

bool load(const char* path, int& gloveCount, Glove data[]) {
    ifstream fin(path);

    fin >> gloveCount;
    
    for (size_t i = 0; i < gloveCount; i++) {
        fin >> data[i].gender >> data[i].hand >> data[i].size;
    }

    return true;
}

int countFemalePairs(const Glove data[], int gloveCount) {
    int leftCount[MAX_SIZE] = {0};
    int rightCount[MAX_SIZE] = {0};
    int fpairs = 0;

    for (int i = 0; i < gloveCount; i++) {
        if (data[i].gender == 4) {
            if (data[i].hand == 1) {
                leftCount[data[i].size]++;
            } else if (data[i].hand == 2) {
                rightCount[data[i].size]++;
            }
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        fpairs += min(leftCount[i], rightCount[i]);
    }
    return fpairs;
}

int countMalePairs(const Glove data[], int gloveCount) {
    int leftCount[MAX_SIZE] = {0};
    int rightCount[MAX_SIZE] = {0};
    int mpairs = 0;

    for (int i = 0; i < gloveCount; i++) {
        if (data[i].gender == 3) {
            if (data[i].hand == 1) {
                leftCount[data[i].size]++;
            } else if (data[i].hand == 2) {
                rightCount[data[i].size]++;
            }
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        mpairs += min(leftCount[i], rightCount[i]);
    }
    return mpairs;
}