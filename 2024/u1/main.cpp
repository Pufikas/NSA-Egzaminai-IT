#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Zaidejas {
    int nr;
    int pBaudos; // pataikytos baudos
    int mBaudos; // mestos baudos
    int pDvit;
    int mDvit;
    int pTrit;
    int mTrit;
    int zaista = 0;
};

void skaityti(int &n, Zaidejas Z[]) {
    ifstream fin("u1.txt");
    fin >> n;

    int zaidejai = 0;
    for (int i = 0; i < n; i++) {
        int nr, pb, mb, pd, md, pt, mt;
        fin >> nr >> pb >> mb >> pd >> md >> pt >> mt;

        bool rastas = false;
        for (int j = 0; j < zaidejai; j++) { // ieskom ar zaidejas yra sarase
            if (Z[j].nr == nr) {
                Z[j].pBaudos += pb;
                Z[j].mBaudos += mb;
                Z[j].pDvit += pd;
                Z[j].mDvit += md;
                Z[j].pTrit += pt;
                Z[j].mTrit += mt;
                Z[j].zaista++;
                rastas = true;
                break;
            }
        }

        if (!rastas) { // jeigu naujas zaidejas dedam i sarasa
            Z[zaidejai] = {nr, pb, mb, pd, md, pt, mt, 1};
            // 1 atlieka taip pat kaip -> Z[zaidejai].zaista = 1;
            zaidejai++;
        }
    }

    n = zaidejai;

    fin.close();
}

void skaiciuoti(int &n, Zaidejas Z[]) {
    ofstream fout("u1res.txt");
    int didz = 0;

    // suranda didziausia kieki zaista rungtyniu
    for (int i = 0; i < n; i++) {
        if (Z[i].zaista > didz) {
            didz = Z[i].zaista;
        }
    }

    fout << didz << endl;
    for (int a = 0; a < n; a++) {
        if (Z[a].zaista != didz) continue;

        double vid = (Z[a].pBaudos + Z[a].pDvit * 2 + Z[a].pTrit * 3) * 1.0 / Z[a].zaista;
        double mestaIsv = (Z[a].mBaudos + Z[a].mDvit + Z[a].mTrit);
        double pataikytaIsv = (Z[a].pBaudos + Z[a].pDvit + Z[a].pTrit);

        int santykis = (pataikytaIsv / mestaIsv) * 100;
       

        fout << Z[a].nr << " " << fixed << setprecision(1) << vid << " " << santykis << " %" << endl;
    }

    fout.close();
}


int main() {
    int n;
    Zaidejas Z[100];

    skaityti(n, Z);
    skaiciuoti(n, Z);

    return 0;
}