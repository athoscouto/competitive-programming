#include <bits/stdc++.h>

using namespace std;

int value(char C) {
    if (C == 'T')
        return 10;
    else if (C == 'J')
        return 11;
    else if (C == 'Q')
        return 12;
    else if (C == 'K')
        return 13;
    else if (C == 'A')
        return 14;
    else
        return static_cast<int>(C - '0');
}

int straight(char hand[5][2]) {
    bool diffs[4] = {false};
    int diff, val;
    int counter = 0;
    int start = value(hand[0][0]);
    int max = start;

    for (int i = 1; i < 5; i++) {
        val = value(hand[i][0]);
        if (val > max)
            max = val;
        diff = abs(start - val);
        if (diff > 4 || diffs[diff])
            return 0;
        else {
            diffs[diff] = true;
            counter++;
        }
    }
    return max;
}

int flush(char hand[5][2]) {
    char suit = hand[0][1];
    int max = value(hand[0][0]);
    int val;
    for (int i = 1; i < 5; i++) {
        val = value(hand[i][0]);
        if (val > max)
            max = val;
        if (hand[i][1] != suit)
            return 0;
    }
    return max;
}

int pairs(char hand[5][2]) {
    int counter = 0, maxi = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand[i][0] == hand[j][0]) {
                counter++;
                maxi = max(value(hand[i][0]), maxi);
            }
        }
    }
    return 100*counter + maxi;
}

int four(char hand[5][2]) {
    char first = hand[0][0], sec = hand[1][0];
    int i = 0, j = 0;

    for (int k = 2; k < 5; k++) {
        if (hand[k][0] == first)
            i++;
        else if (hand[k][0] == sec)
            j++;
        else
            return 0;
    }
    if (i == 4)
        return value(first);
    if (j == 4)
        return value(sec);

    return 0;
}

int maxi(char hand[5][2]) {
    int max = 0;
    for (int i = 0; i < 5; i++)
        if (value(hand[i][0]) > max)
            max = value(hand[i][0]);
    return max;
}

int rank(char hand[5][2]) {
    int flus = flush(hand);
    int straigh = straight(hand);
    int fou = four(hand);
    int pair = pairs(hand);

    if (flus) {
        if (straigh)
            return 5000 + flus;
        else
            return 2000 + flus;
    }
    if (fou)
        return 4000 + fou;
    if (pair / 100 == 4)
        return 3000 + pair;
    if (straigh)
        return 1000 + straigh;
    if (pair > 100)
        return pair;
    else
        return maxi(hand);

}
int main() {
    char hands[2][5][2];

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 2; k++)
                    scanf(" %c", &hands[i][j][k]);

        printf("Black Rank: %d\n", rank(hands[0]));
        printf("White Rank: %d\n", rank(hands[1]));
        /*
        if (rank(hands[0]) > rank(hands[1]))
            printf("Black wins.\n");
        else if (rank(hands[0]) == rank(hands[1]))
            printf("Tie.\n");
        else
            printf("White wins.\n");
        */
    }
    return 0;
}
