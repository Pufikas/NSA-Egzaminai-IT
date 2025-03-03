#include <fstream>
using namespace std;

#define MAX_MER 10
#define MAX_MOK 20
#define MAX_DISH_COUNT 10

void load(const char* path, int Mokinys[MAX_MOK], int DISH[MAX_MER]);
void calculate(int Mokinys[MAX_MOK], int DISH[MAX_MER]);
void save(const char* path, int Mokinys[MAX_MOK]);

int main() {
    int Mokinys[MAX_MOK] = {0};
    int DISH[MAX_DISH_COUNT];

    load("u1.txt", Mokinys, DISH);
    calculate(Mokinys, DISH);
    save("u1res.txt", Mokinys);
}

void calculate(int Mokinys[MAX_MOK], int DISH[MAX_MER]) {
    for (int i = 0; i < MAX_MER; i++) {
        int student = i + 1;
        while (DISH[i] > 0 && i < MAX_MOK) {
            Mokinys[student]++; // eats one dish
            DISH[i]--; // - dish counter
            student++; // move to next student
        }
    }       
}

void save(const char* path, int Mokinys[MAX_MOK]) {
    ofstream fout(path);

    for (int i = 0; i < MAX_MOK; i++) {
        fout << Mokinys[i] << " ";
    }

    fout.close();
}

void load(const char* path, int Mokinys[MAX_MOK], int DISH[MAX_MER]) {
    fstream fin(path);

    for (int i = 0; i < MAX_MER; i++) {
        fin >> Mokinys[i];

        DISH[i] = MAX_DISH_COUNT - Mokinys[i]; 
    }

    for (int i = MAX_MER; i < MAX_MOK; i++) {
        Mokinys[i] = 0;
    }

    fin.close();
}