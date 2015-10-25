#include <bits/stdc++.h>

using namespace std;

int main() {
    int C, n, k, d, g, c[21];
    long long an, pn;
    double root;
    scanf("%d", &C);
    while(C--) {
        scanf("%d", &g);
        for(int i=0; i<=g; ++i) scanf("%d", &c[i]);
        scanf("%d", &d); scanf("%d", &k);

        root = sqrt(1 + 8.0*k/d)/2 - 0.5;
        n = int(root);
        if (root != ceilf(root)) n++;
        an = 0; pn=1;
        for(int i=0; i<=g; ++i) {
            an += c[i]*pn;
            pn *= n;
        }
        printf("%lld\n", an);
    }
    return 0;
}
