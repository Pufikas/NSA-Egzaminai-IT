#include <fstream>

using namespace std;


struct Player {
    int number;
    int bench;
    int play;
};

void load(const char* path, Player players[], int& n);
void sortByPlaytime(Player players[], int n);
void sortByNumber(Player players[], int n);
void save(const char* path, Player players[], int n);

int main() {
    Player players[12];
    int n;

    load("u1.txt", players, n);
    sortByPlaytime(players, n);
    save("u1res.txt", players, n);

    return 0;
}


void load(const char* path, Player players[], int& n) {
    fstream fin(path);
    int t, time;

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> players[i].number >> t;

        players[i].play = 0;
        players[i].bench = 0;

        for (int j = 0; j < t; j++) {
            fin >> time;
            if (time > 0) {
                players[i].play += time;
            } else {
                players[i].bench += -time;
            }
        }
    }

    fin.close();
}


void sortByPlaytime(Player players[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (players[i].play < players[j].play || 
            (players[i].play == players[j].play && players[i].number > players[j].number)) {
                swap(players[i], players[j]);
            }
        }
    }
}


void sortByNumber(Player players[], int n) {
    // sort by number in asc order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (players[i].number > players[j].number) {
                swap(players[i], players[j]);
            }
        }
    }
}

void save(const char* path, Player players[], int n) {
    ofstream fout(path);
    int maxPlay = 0, maxPlayNum = 0, maxBench = 0, maxBenchNum = 0;

    // not getting the correct top 5 players
    Player top5[5];
    for (int i = 0; i < 5; i++) {
        top5[i] = players[i];
    }
    sortByNumber(top5, 5);

    // top 5 players by playtime
    for (int i = 0; i < 5; i++) {
        fout << top5[i].number << " ";
    }
    fout << endl;

    // player with max play time
    for (int i = 0; i < n; i++) {
        if (players[i].play > maxPlay) {
            maxPlay = players[i].play;
            maxPlayNum = players[i].number;
        }
    }
    fout << maxPlayNum << " " << maxPlay << endl;

    // player with max bench time
    for (int i = 0; i < n; i++) {
        if (players[i].bench > maxBench) {
            maxBench = players[i].bench;
            maxBenchNum = players[i].number;
        }
    }
    fout << maxBenchNum << " " << maxBench << endl;

    fout.close();
}

