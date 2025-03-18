#include <iostream>
#include <fstream>

using namespace std;

void skaityti(int& n1, int& n3, int& n5, int& k, int& kn1, int& kn3, int& kn5, int& isl) {
    ifstream fin("u1.txt");

    fin >> n1 >> n3 >> n5 >> k;
    fin >> isl >> kn1 >> kn3 >> kn5; // islaidos, indu kainos

    fin.close();
}

void skaiciuoti(int& n1, int& n3, int& n5, int& k, int& ip1, int& ip3, int& ip5, int& liko, int& likn5, int& likn3, int& likn1) {
    ip5 = min(n5, k/5); // ipilta i 5l inda
    k -= ip5 * 5; // kiek liko aliejaus po ipilimo

    ip3 = min(n3, k/3);
    k -= ip3 * 3;

    ip1 = min(n1, k);
    k -= ip1;

    liko = k;
    likn5 = n5 - ip5;
    likn3 = n3 - ip3;
    likn1 = n1 - ip1;


    cout << ip5 << " " << ip3 << " " << ip1 << " " << k << endl;

}


void papildomiIndai(int liko, int& papn1, int& papn3, int& papn5) {
    papn5 = liko / 5;
    liko -= papn5 * 5;

    papn3 = liko / 3;
    liko -= papn3 * 3;

    papn1 = liko;
}


void rasyti(int ip1, int ip3, int ip5, int liko, int likn1, int likn3, int likn5, int papn1, int papn3, int papn5) {
    ofstream fout("u1res.txt");

    fout << ip1 << " " << ip3 << " " << ip5 << " " << liko << endl;
    fout << likn1 << " " << likn3 << " " << likn5 << endl;
    fout << papn1 << " " << papn3 << " " << papn5 << endl;

    fout.close();
}

int main() {
    int n1, n3, n5, k, kn1, kn3, kn5, isl;
    int ip1 = 0, ip3 = 0, ip5 = 0, liko = 0;
    int likn1 = 0, likn3 = 0, likn5 = 0;
    int papn1 = 0, papn3 = 0, papn5 = 0;

    skaityti(n1, n3, n5, k, kn1, kn3, kn5, isl);
    skaiciuoti(n1, n3, n5, k, ip1, ip3, ip5, liko, likn1, likn3, likn5);
    papildomiIndai(liko, papn1, papn3, papn5);
    rasyti(ip1, ip3, ip5, liko, likn1, likn3, likn5, papn1, papn3, papn5);

    return 0;
}   