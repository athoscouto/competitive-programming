#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int counter = 0;
    char c;
    while(scanf(" %c", &c) != EOF) {
        counter <<= 1;
        if (c == '7')
            counter += 2;
        if (c == '4')
            counter++;
    }

    printf("%d", counter);

    return 0;
}
