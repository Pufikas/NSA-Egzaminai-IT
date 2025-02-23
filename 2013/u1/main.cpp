#include <fstream>

using namespace std;

struct Imone {
    string name;
    int coordinate[2];
};

void load(const char* path, Imone data[], int& n, int& m);
void save(const char* path, Imone data[], int& n, int& m);

int main() {
    int n, m;
    Imone data[50];
    
    load("u1.txt", data, n, m);
    save("u1res.txt", data, n, m);
}

void calculate(Imone data[], int& n, int& m) {

}

void save(const char* path, Imone data[], int& n, int& m) {
    ofstream fout(path);

    for (int i = 0; i < n; i++) {
        fout << data[i].name << " " << data[i].coordinate[0] << " " << data[i].coordinate[1] << endl;
    }
}


void load(const char* path, Imone data[], int& n, int& m) {
    fstream fin(path);

    fin >> n >> m;

    string line;
    for (int i = 0; i < n; i++) {
        char nameBuffer[11]; // 10 chars + null terminator
        fin.read(nameBuffer, 10);
        nameBuffer[10] = '\0'; // null terminator
        data[i].name = nameBuffer;

        fin >> data[i].coordinate[0] >> data[i].coordinate[1];
        
    }

    fin.close();
}


