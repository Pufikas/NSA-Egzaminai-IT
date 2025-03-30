#include <fstream>
#include <iostream>

using namespace std;

struct Begimai {
    int diena;
    int rytoLaikas;
    int vakaroLaikas;
};

void skaityti(int &d, Begimai data[]) {
    int m, h;
    ifstream fin("u1.txt");

    fin >> d;

    for (int i = 0; i < d; i++) {
        fin >> data[i].diena;

        // rytas
        fin >> h >> m;
        int rytPr = h*60 + m;
        fin >> h >> m;
        int rytPa = h*60 + m;

        // jeigu ryto pradzia ir pabaiga yra 0 praleidziam ir rasom 0, jeigu ne atimam ryto pabaiga is pradzios 
        data[i].rytoLaikas = (rytPr == 0 || rytPa == 0) ? 0 : rytPa - rytPr;

        // vakaras
        fin >> h >> m;
        int vakPr = h*60 + m;
        fin >> h >> m;
        int vakPa = h*60 + m;

        data[i].vakaroLaikas = (vakPr == 0 || vakPa == 0) ? 0 : vakPa - vakPr;
    }
    
    fin.close();
}

int main() {
    Begimai data[31];
    int d;

    skaityti(d, data);

    for (int i = 0; i < d; i++) {
        cout << data[i].rytoLaikas << " " << data[i].vakaroLaikas << endl;
    }
}