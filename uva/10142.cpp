#include <bits/stdc++.h>

using namespace std;

char candidates[21][80];
int votes[21][3];

struct a {
    int votes;
    int third[21];
};

struct b {
    int votes;
    struct a second[21];
};


int main() {

    int n, cases;

    scanf("%d", &cases);

    for (int counter = 0; counter < cases; counter++) {
        scanf(" %d", &n);
        scanf(" ");
        for (int i = 1; i <= n; i++)
            fgets(candidates[i], 80, stdin);

        bool not_running[n + 1] = {false};

        // Creates and initializes the struct with 0 on all values
        b votes[n + 1];
        for (int i = 1; i <= n; i++) {
            votes[i].votes = 0;
            for (int j = 1; j <= n; j++) {
                votes[i].second[j].votes = 0;
                for (int k = 1; k <= n; k++) {
                    votes[i].second[j].third[k] = 0;
                }
            }
        }

        // Get the votes and distribute them
        int ft, sc, th;
        char buffer[80];
        while(true) {
            fgets(buffer, 80, stdin);
            if (buffer[0] == '\n' || feof(stdin))
                break;
            sscanf(buffer, "%d %d %d", &ft, &sc, &th);
            votes[ft].votes++;
            votes[ft].second[sc].votes++;
            votes[ft].second[sc].third[th]++;
        }

        int total = 0, max = 0, imax = 0, min = INT_MAX;
        int candidates_left = n;

        while (true) {
            // COMPUTE MAX / MIN / TOTAL VOTES
            for (int i = 1; i <= n; i++) {
                if (not_running[i])
                    continue;
                total += votes[i].votes;
                if (votes[i].votes >= max) {
                    max = votes[i].votes;
                    imax = i;
                }
                if (votes[i].votes <= min)
                    min = votes[i].votes;
            }
            // IF MAX > 50% TOTAL WE HAVE A WINNER!
            if (max > (total / 2)) {
                fputs(candidates[imax], stdout);
                printf("A");
                return 0;
            }
            // IF MIN == MAX: WE HAVE WINNER(S)
            if (min == max) {
                for (int i = 1; i <= n; i++) {
                    if (votes[i].votes == max)
                        fputs(candidates[i], stdout);
                return 0;
                }
            }
            // IF NOT: REMOVE THE ONES WITH MIN VOTES
            for (int i = 1; i <= n; i++) {
                if (votes[i].votes == min) {
                    not_running[i] = true;
                    candidates_left--;
                    // Redistributes the votes of the loser to the running candidates
                    for (int j = 1; j <= n; j++) {
                        votes[j].votes += votes[i].second[j].votes;
                        for (int k = 1; k <= n; k++) {
                            votes[j].second[k].votes += votes[i].second[j].third[k];
                        }
                    }
                }
            }
        }
    }
    return 0;
}
