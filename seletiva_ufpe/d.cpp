#include <bits/stdc++.h>
using namespace std;

int T, t, n, a, b, x, y;

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        a = b = 0;
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            scanf("%d %d", &x, &y);
            if (x == y) a++, b++;
            else if (x > y) a += b, b = 0;
            else b += a, a = 0;
        }
        printf("Caso #%d: %d %d\n", t, a, b);
    }

    return 0;
}
