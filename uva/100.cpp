#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    while(true) {
        int max = INT_MIN;

        for(int k = i; k <= j; k++) {
            int n = k, counter = 1;
            while(n != 1) {
                n % 2 ? (n = 3 * n + 1) : (n /= 2);
                counter++;
            }
            if (counter > max) max = counter;
        }

        printf("%d %d %d", i, j, max);
        if (scanf("%d %d", &i, &j) != EOF) printf("\n");
        else break;
    }
    return 0;
}
