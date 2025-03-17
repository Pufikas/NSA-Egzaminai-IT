#include <iostream>
#include <fstream>

using namespace std;

void skaityti(int& n1, int& n3, int& n5, int& k, int& kn1, int& kn3, int& kn5, int& isl) {
    ifstream fin("u1.txt");

    fin >> n1 >> n3 >> n5 >> k;
    fin >> isl >> kn1 >> kn3 >> kn5; // islaidos, indu kainos

    fin.close();
}

void skaiciuoti(int& n1, int& n3, int& n5, int& k, int& ip1, int& ip3, int& ip5, int& liko, int& likn5, int& likn3, int& lik1) {
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

int main() {
    int n1, n3, n5, k, kn1, kn3, kn5, isl;
    int ip5, ip3, ip1, liko;
    int lik5, lik3, lik1;

    skaityti(n1, n3, n5, k, kn1, kn3, kn5, isl);
    skaiciuoti(n1, n3, n5, k, ip1, ip3, ip5, liko, likn5, likn3, likn1);

    return 0;
}