#include <fstream>

using namespace std;

struct Pratimas {
    string name;
    int count;
};

void rusiuoti(int& uniqueCount, Pratimas*& data);
void load(const char* path, int& n, int& uniqueCount, Pratimas*& data);
void save(const char* path, int& uniqueCount, Pratimas*& data);

int main() {
    int n;
    int uniqueCount = 0;
    Pratimas* data = nullptr;

    load("u2.txt", n, uniqueCount, data);
    rusiuoti(uniqueCount, data);
    save("u2res.txt", uniqueCount, data);
  
    delete[] data;
    return 0;
}

void rusiuoti(int& uniqueCount, Pratimas*& data) {
    for (int i = 0; i < uniqueCount; i++) {
        for (int j = i+1; j < uniqueCount; j++) {
            if (data[i].count < data[j].count) {
                swap(data[i], data[j]);
            }
        }
    }
}

void save(const char* path, int& uniqueCount, Pratimas*& data) {
    ofstream fout(path);

    for (int i = 0; i < uniqueCount; i++) {
        fout << data[i].name << " " << data[i].count << endl;
    }

    fout.close();
}

void load(const char* path, int& n, int& uniqueCount, Pratimas*& data) {
    ifstream fin(path);
    
    int kiekis;
    string pratimas;
    fin >> n;

    data = new Pratimas[n];
    for (int i = 0; i < n; i++) {
        fin >> pratimas >> kiekis;
        bool yra = false;
        
        for (int j = 0; j < n; j++) {
            // exercise exists so update its count
            if (data[j].name == pratimas) {
                data[j].count += kiekis;
                yra = true;
                break;
            }
        }

        if (!yra) {
            data[uniqueCount].name = pratimas;
            data[uniqueCount].count = kiekis;
            uniqueCount++;
        }
    }

    fin.close();
}