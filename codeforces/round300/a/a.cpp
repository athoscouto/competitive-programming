#include <bits/stdc++.h>

using namespace std;

int main() {
    char chars[100000];
    char code[] = {'C', 'O', 'D', 'E', 'F', 'O', 'R', 'C', 'E', 'S'};
    char temp;
    int size = 0;

    while(scanf("%c", &temp) != EOF && temp !='\n') chars[size++] = temp;

    int k = 0;
    int j;
    while(code[k] == chars[k]) {
        k++;
        if (k == 10)
            break;
    }
    for(j = 0; j < 10 - k; j++)
        if (code[9 - j] != chars[size - 1 - j])
            break;
    if (k + j == 10) {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");

    return 0;
}
