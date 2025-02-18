#include <fstream>

using namespace std;

#define MAX_GLOVES 30
#define MAX_SIZE 100

struct Glove {
    int gender;
    int hand;
    int size;
};

bool load(const char* path, int& gloveCount, Glove data[]);
void countPairs(const Glove data[], int gloveCount, int& fpairs, int& mpairs, int& leftoverFpairs, int& leftoverMpairs);
bool save(const char* path, int fpairs, int mpairs, int leftoverFpairs, int leftoverMpairs);

int main() {
    Glove data[MAX_GLOVES];
    int gloveCount = 0;
    int fpairs, mpairs, leftoverFpairs, leftoverMpairs;

    if (!load("u1.txt", gloveCount, data)) return 1;
    countPairs(data, gloveCount, fpairs, mpairs, leftoverFpairs, leftoverMpairs);
    return !save("u1res.txt", fpairs, mpairs, leftoverFpairs, leftoverMpairs);
}

bool load(const char* path, int& gloveCount, Glove data[]) {
    ifstream fin(path);

    fin >> gloveCount;
    
    for (size_t i = 0; i < gloveCount; i++) {
        fin >> data[i].gender >> data[i].hand >> data[i].size;
    }

    return true;
}

bool save(const char* path, int fpairs, int mpairs, int leftoverFpairs, int leftoverMpairs) {
    ofstream fout(path);

    fout << fpairs << endl << mpairs << endl << leftoverFpairs << endl << leftoverMpairs;

    fout.close();
    return true;
}


void countPairs(const Glove data[], int gloveCount, int& fpairs, int& mpairs, int& leftoverFpairs, int& leftoverMpairs) {
    int maleLeftCount[MAX_SIZE] = {0};
    int maleRightCount[MAX_SIZE] = {0};
    int femaleLeftCount[MAX_SIZE] = {0};
    int femaleRightCount[MAX_SIZE] = {0};
    int totalFgloves = 0, totalMgloves = 0;
    fpairs = 0, mpairs = 0, leftoverFpairs = 0, leftoverMpairs = 0;

    for (int i = 0; i < gloveCount; i++) {
        if (data[i].gender == 4) {
            if (data[i].hand == 1) {
                femaleLeftCount[data[i].size]++;
            } else if (data[i].hand == 2) {
                femaleRightCount[data[i].size]++;
            }
        } else if (data[i].gender == 3) {
            if (data[i].hand == 1) {
                maleLeftCount[data[i].size]++;
            } else if (data[i].hand == 2) {
                maleRightCount[data[i].size]++;
            }
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        fpairs += min(femaleLeftCount[i], femaleRightCount[i]);
        mpairs += min(maleLeftCount[i], maleRightCount[i]);

        totalFgloves += femaleLeftCount[i] + femaleRightCount[i];
        totalMgloves += maleLeftCount[i] + maleRightCount[i];
    }

    leftoverFpairs = totalFgloves - (2 * fpairs);
    leftoverMpairs = totalMgloves - (2 * mpairs);
}
