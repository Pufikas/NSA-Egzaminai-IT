#include <fstream>
#include <iomanip>

#include <iostream>

using namespace std;

struct God {
    string name;
    int* numbers;
    int sum;
    int evenCount;
};

void calculate(God gods[], int& n, int& k);
void save(const char* path, God gods[], int& n, int& k);
void load(const char* path, God gods[], int& n, int& k);

int main() {
    int n, k;
    God gods[50];

    load("u2.txt", gods, n, k);
    calculate(gods, n, k);
    save("u2res.txt", gods, n, k);
}

void calculate(God gods[], int& n, int& k) {
    for (int i = 0; i < n; i++) {
        gods[i].sum = 0;
        gods[i].evenCount = 0;
        
        for (int j = 0; j < k; j++) {
            gods[i].sum += gods[i].numbers[j];
        
            if (gods[i].numbers[j] % 2 == 0) {
                gods[i].evenCount++;
            }
        }
        cout << gods[i].name << ": " << gods[i].sum << " even " << gods[i].evenCount << endl;
    }
}


void save(const char* path, God gods[], int& n, int& k) {
    ofstream fout(path);
    int maxSum = 0, maxEvenCount = 0, godIndex = 0;

    for (int i = 1; i < n; i++) {

        if (gods[i].sum > maxSum) {
            maxSum = gods[i].sum;
            maxEvenCount = gods[i].evenCount;
            godIndex = i;
        } else if (gods[i].sum == maxSum) {
            if (gods[i].evenCount > maxEvenCount) {
                maxEvenCount = gods[i].evenCount;
                godIndex = i;
            }
        }
    }
    // setw(11), 10 for name + 1 space
    fout << setw(11) << left << gods[godIndex].name << gods[godIndex].sum;
}

void load(const char* path, God gods[], int& n, int& k) {
    fstream fin(path);

    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin >> gods[i].name;
        gods[i].numbers = new int[k]; // allocate space for numbers
        for (int j = 0; j < k; j++) {
            fin >> gods[i].numbers[j];
        }
    }
    
    fin.close();
}
