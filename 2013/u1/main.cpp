#include <fstream>
#include <algorithm>

using namespace std;

struct Company {
    string name;
    int coordinate[2];
};

void calculate(Company data[], int& n, int& m, string& lastCompany, int& trips, int& sum);
void load(const char* path, Company data[], int& n, int& m);
void save(const char* path, string& lastCompany, int trips, int sum);

int main() {
    int n, m, trips = 0, sum = 0;
    string lastCompany;
    Company data[50];
    
    load("u1.txt", data, n, m);
    calculate(data, n, m, lastCompany, trips, sum);
    save("u1res.txt", lastCompany, trips, sum);
}

void calculate(Company data[], int& n, int& m, string& lastCompany, int& trips, int& sum) {
    int startCoords[2] = {0, 0};
    
    for (int i = 0; i < n; i++) {
        int distance = 2 * (abs(data[i].coordinate[0]) + abs(data[i].coordinate[1]));

        if (sum + distance <= m) {
            sum += distance;
            trips++;
        } else {
            lastCompany = data[i - 1].name;
            lastCompany.erase(remove(lastCompany.begin(), lastCompany.end(), '\n'), lastCompany.cend());
            // remove the hidden '\n' from a string
            break;
        }
    }
}


void save(const char* path, string& lastCompany, int trips, int sum) {
    ofstream fout(path);

    fout << trips << " " << sum << " " << lastCompany;

    fout.close();
}


void load(const char* path, Company data[], int& n, int& m) {
    fstream fin(path);

    fin >> n >> m;

    for (int i = 0; i < n; i++) {
        char nameBuffer[11]; // 10 chars + null terminator
        fin.read(nameBuffer, 10);
        nameBuffer[10] = '\0'; // null terminator
        data[i].name = nameBuffer;

        fin >> data[i].coordinate[0] >> data[i].coordinate[1];
        
    }

    fin.close();
}


// failas u1.txt originaliai buvo su – zenklais kuris nera tiesiog - (minusinis zenklas), nezinau ar cia specialiai taip mandrai ar ka jie ten masto
// programa veikia tik tada kai yra normalus - zenklai, o ne kazkokie – :)