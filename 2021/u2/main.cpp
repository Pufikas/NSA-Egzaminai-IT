#include <fstream>

using namespace std;

struct Mokinys {
    string vardas;
    string dalykas;
    int pazymiai[20];
    int pazKiekis;
    int vidurkis;
};

struct Dalykas {
    string pav;
    int mokSk;
    string mokiniai[30];
};

void skaityti(int &m, Mokinys data[]) {
    ifstream fin("u2.txt");

    fin >> m;
    for (int i = 0; i < m; i++) {
        int suma = 0;
        fin >> data[i].vardas >> data[i].dalykas >> data[i].pazKiekis;

        for (int j = 0; j < data[i].pazKiekis; j++) {
            fin >> data[i].pazymiai[j];
            suma += data[i].pazymiai[j];
        }
        data[i].vidurkis = suma / data[i].pazKiekis;
    }

    fin.close();
}

// randa megstamiausius mok dalykus
void megstamiausi(int &m, int &d, Mokinys data[], Dalykas dal[]) {
    for (int i = 0; i < m; i++) {
        if (data[i].vidurkis >= 9) {
            bool rastas = false; // ar jau yra mokomasis dalykas sarase
            for (int j = 0; j < d; j++) {
                if (dal[j].pav == data[i].dalykas) { 
                    // tikrina ar dabartinis mokinio dalykas jau yra musu dalyku sarase (dal[])
                    // jei yra - prideda mokini prie to dalyko
                    dal[j].mokiniai[dal[j].mokSk++] = data[i].vardas;
                    rastas = true;
                    break;
                }
            }

            // jei nera - sukuria nauja irasa
            if (!rastas) {
                dal[d].pav = data[i].dalykas;
                dal[d].mokiniai[0] = data[i].vardas;
                dal[d].mokSk = 1;
                d++;
            }
        }
    }
}

void rikiuoti(int d, Dalykas dal[]) {
    for (int i = 0; i < d; i++) {
        for (int j = i+1; j < d; j++) {
            if (dal[i].mokSk < dal[j].mokSk || 
                (dal[i].mokSk == dal[j].mokSk && dal[i].pav > dal[j].pav)) {
                    swap(dal[i], dal[j]);
            }
        }
    }
}


void rasyti(int d, Dalykas dal[]) {
    ofstream fout("u2res.txt");
    
    if (d == 0) {
        fout << "Neatitinka vidurkis" << endl;
        return;
    }
    
    for (int i = 0; i < d; i++) {
        fout << dal[i].pav << " " << dal[i].mokSk << endl;
        for (int j = 0; j < dal[i].mokSk; j++) {
            fout << dal[i].mokiniai[j] << endl;
        }
    }
    
    fout.close();
}

int main() {
    int m, d = 0;
    Mokinys data[30];
    Dalykas dal[30];

    skaityti(m, data);
    megstamiausi(m, d, data, dal);
    rikiuoti(d, dal);
    rasyti(d, dal);

    return 0;
}