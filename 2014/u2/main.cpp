#include <fstream>
#include <cstring>

using namespace std;

#define MAX_SEQUENCES 10
#define MAX_SEQUENCE_LENGTH 30
#define MAX_STRING 50

void load(const char* path, int startingCoords[], int goal[], int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH], int sequenceLength[], int& n);
void save(const char* path, char results[MAX_SEQUENCES][MAX_STRING], int n);
void executeSequence(int startingCoords[], int goal[], int sequence[], int seqLength, char result[MAX_STRING]);

int main() {
    int n, k;
    int startingCoords[2] = {0};
    int goal[2] = {0};
    int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH] = {0};
    int sequenceLength[MAX_SEQUENCES] = {0};
    char results[MAX_SEQUENCES][MAX_STRING] = {0};

    load("u2.txt", startingCoords, goal, coords, sequenceLength, n);
    for (int i = 0; i < n; i++) {
        executeSequence(startingCoords, goal, coords[i], sequenceLength[i], results[i]);
    }
    save("u2rez.txt", results, n);
    return 0;
}


void executeSequence(int startingCoords[], int goal[], int sequence[], int seqLength, char result[MAX_STRING]) {
    int x = startingCoords[0], y = startingCoords[1];
    char executedCommands[MAX_STRING] = {0};
    int count = 0;
    bool reachedGoal = false;

    for (int i = 0; i < seqLength; i++) {
        
        if (sequence[i] == 1) y++;
        else if (sequence[i] == 2) x++;
        else if (sequence[i] == 3) y--;
        else if (sequence[i] == 4) x--;

        char temp[4];  
        sprintf(temp, "%d ", sequence[i]);
        strcat(executedCommands, temp);
        
        count++;

        if (x == goal[0] && y == goal[1]) {
            reachedGoal = true;
            break;
        }
    }

    // format the output
    // %-20s 20 chars (pasiektas tikslas), %s executedCommands, %d count
    if (reachedGoal) {
        sprintf(result, "%-20s%s%d", "pasiektas tikslas", executedCommands, count);
    } else {
        sprintf(result, "%-20s%s%d", "sekos pabaiga", executedCommands, count);
    }
    
}

void load(const char* path, int startingCoords[], int goal[], int coords[MAX_SEQUENCES][MAX_SEQUENCE_LENGTH], int sequenceLength[], int& n) {
    fstream fin(path);

    fin >> startingCoords[0] >> startingCoords[1];
    fin >> goal[0] >> goal[1];
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> sequenceLength[i];

        for (int j = 0; j < sequenceLength[i]; j++) {
            fin >> coords[i][j];
        }
    }

    fin.close();
}

void save(const char* path, char results[MAX_SEQUENCES][MAX_STRING], int n) {
    ofstream fout(path);

    for (int i = 0; i < n; i++) {
        fout << results[i] << endl;
    }

    fout.close();
}