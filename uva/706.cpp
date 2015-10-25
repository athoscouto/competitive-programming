#include <bits/stdc++.h>

const int NUM_DIGITS = 8;
using namespace std;
/*     0
*    -----
*  1|     |2
*   |  3  |
*    -----
*  4|     |5
*   |  6  |
*    -----
*
* numbers represents which characters are in which position
* in the number's LCD representation. The position indexes are
* shown in the drawing above
*/

char numbers[10][7] = {
    {'-', '|', '|', ' ', '|', '|', '-'}, // Representation of 0
    {' ', ' ', '|', ' ', ' ', '|', ' '}, // Representation of 1
    {'-', ' ', '|', '-', '|', ' ', '-'}, // Representation of 2
    {'-', ' ', '|', '-', ' ', '|', '-'}, // Representation of 3
    {' ', '|', '|', '-', ' ', '|', ' '}, // Representation of 4
    {'-', '|', ' ', '-', ' ', '|', '-'}, // Representation of 5
    {'-', '|', ' ', '-', '|', '|', '-'}, // Representation of 6
    {'-', ' ', '|', ' ', ' ', '|', ' '}, // Representation of 7
    {'-', '|', '|', '-', '|', '|', '-'}, // Representation of 8
    {'-', '|', '|', '-', ' ', '|', '-'}}; // Representation of 9

// PRINT THE LINES WITH (-)
// num_line IS THE INDEX OF THE REPRESENTATION WHERE (-) APPEARS, IT IS: 0, 3 OR 6
void print_line(int num_line, int i, int s, int digits[]) {

    for (int j = i; j < NUM_DIGITS; j++) {
        printf(" ");
        for(int k = 0; k < s; k++)
            printf("%c", numbers[digits[j]][num_line]);
        printf("  ");
    }
    printf("\n");
}

// PRINT THE LINES WITH (|)
void print_column(bool lower, int i, int s, int digits[]) {
    //lower INDICATES IF WE ARE PRINTING (|) OF THE LOWER PART OF THE DIGIT

    // s DEFINES THE NUMBER OF TIMES THE LINE IS GOING TO BE PRINT
    for(int l = 0; l < s; l++) {
        for (int j = i; j < NUM_DIGITS; j++) {
            printf("%c", numbers[digits[j]][1 + lower * 3]);
            for(int k = 0; k < s; k++)
                printf(" ");
            printf("%c", numbers[digits[j]][2 + lower * 3]);
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n, s;
    int digits[NUM_DIGITS];
    while (scanf(" %d %d", &s, &n) && (s || n)) {
        int i;
        for (i = NUM_DIGITS - 1; i >= 0; i--) {
            digits[i] = n % 10;
            n /= 10;
            if (n == 0) break;
        }
        print_line(0, i, s, digits);
        print_column(false, i, s, digits);
        print_line(3, i, s, digits);
        print_column(true, i, s, digits);
        print_line(6, i, s, digits);
        printf("\n");
    }
    return 0;
}
