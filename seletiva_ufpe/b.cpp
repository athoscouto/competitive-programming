#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int t, T, n, m, k, p[N], q[N], s, r;

int main() {
    scanf("%d", &T);
    while (t++ < T) {
        r = N;
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1; i<=n; ++i) scanf("%d", p+i);
        for(int i=1; i<=m; ++i) scanf("%d", q+i);

        sort(p, p+n+1);
        for(int i=1; i<=m; ++i) q[i] += q[i-1];
        for(int i=1; i<=k; ++i) p[i] += p[i-1];
        s = p[k];

        int i=0;
        for(int j=1; j<=m; ++j) while(q[j] - q[i] >= s) r = min(r, j-i), i++;

        printf("Caso #%d: %d\n", t, r != N ? r : -1);

    }
    return 0;
}
