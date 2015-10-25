#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, k, counter;
    while(scanf("%d", &k) != EOF) {
        counter = 0;
        for(y=k+1; y <= k*y/(y-k); y++) if (((k*y) % (y-k)) == 0) counter++;
        printf("%d\n", counter);
        for(y=k+1; y <= k*y/(y-k); y++) if (((k*y) % (y-k)) == 0) printf("1/%d = 1/%d + 1/%d\n",  k, k*y/(y-k), y);
    }
    return 0;
}
