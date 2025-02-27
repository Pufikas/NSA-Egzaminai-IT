#include <fstream>
#include <algorithm>

using namespace std;

struct Department {
    int votes[3];
};

struct Director {
    int points[3];
};

void load(const char* path, int& k, Department dep[], Director& dir, int totalVotes[]);
void calculate(int k, Department dep[], Director dir, int totalVotes[], int totalPoints[]);
int winner(int totalPoints[]);
void save(const char* path, int totalVotes[], int totalPoints[], int win);

int main() {
    Department dep[10];
    Director dir;
    int totalVotes[3] = {0};
    int totalPoints[3] = {0};
    int k;

    load("U1.txt", k, dep, dir, totalVotes);
    calculate(k, dep, dir, totalVotes, totalPoints);
    int win = winner(totalPoints);
    save("U1rez.txt", totalVotes, totalPoints, win);

    return 0;
}

void save(const char* path, int totalVotes[], int totalPoints[], int win) {
    ofstream fout("u1res.txt");

    fout << totalVotes[0] << " " << totalVotes[1] << " " << totalVotes[2] << endl; 
    fout << totalPoints[0] << " " << totalPoints[1] << " " << totalPoints[2] << endl;
    fout << win << endl;

    fout.close();
}

void load(const char* path, int& k, Department dep[], Director& dir, int totalVotes[]) {
    ifstream fin(path);
    fin >> k;

    for (int i = 0; i < k; i++) {
        fin >> dep[i].votes[0] >> dep[i].votes[1] >> dep[i].votes[2];
        totalVotes[0] += dep[i].votes[0];
        totalVotes[1] += dep[i].votes[1];
        totalVotes[2] += dep[i].votes[2];
    }

    fin >> dir.points[0] >> dir.points[1] >> dir.points[2];
    fin.close();
}

void calculate(int k, Department dep[], Director dir, int totalVotes[], int totalPoints[]) {
    for (int i = 0; i < k; i++) {
        int maxVotes = max({dep[i].votes[0], dep[i].votes[1], dep[i].votes[2]});
        int count = 0;

        for (int j = 0; j < 3; j++) {
            if (dep[i].votes[j] == maxVotes) count++;
        }

        // if 1 toAdd = 4, if 2 toAdd = 2, kitaip 0
        int toAdd = (count == 1) ? 4 : (count == 2) ? 2 : 0;

        for (int j = 0; j < 3; j++) {
            if (dep[i].votes[j] == maxVotes) totalPoints[j] += toAdd;
        }
    }

    int maxPoints = max({totalPoints[0], totalPoints[1], totalPoints[2]});
    // jeigu totalPoints[0] == maxPoints teisinga duoda 1, jei ne 0, taip sudedam kiek yra lyguju
    int ties = (totalPoints[0] == maxPoints) + (totalPoints[1] == maxPoints) + (totalPoints[2] == maxPoints);

    if (ties > 1) {
        for (int j = 0; j < 3; j++) {
            totalPoints[j] += dir.points[j];
        }
    }
}

int winner(int totalPoints[]) {
    int maxPoints = max({totalPoints[0], totalPoints[1], totalPoints[2]});
    
    for (int i = 0; i < 3; i++) {
        if (totalPoints[i] == maxPoints) {
            return i + 1;
        }
    }

    return -1;
}
