#include <bits/stdc++.h>
using namespace std;

const int N = 15, M = 1<<N, INF = 1e9+1;
int t, T, n, c[N], dp[M], k, x, m[N][M];

int main() {
    scanf("%d", &T);
    while (t++ < T) {
        scanf("%d", &n);
        k = 1<<n;

        for(int i=1; i<k; ++i) dp[i] = -INF;

        for(int i=0; i<n; ++i) scanf("%d", c+i);
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) scanf("%d", &m[i][1<<j]);
        for(int i=0; i<n; ++i) m[i][1<<i] = 0;


        for(int i=0; i<n; ++i) for(int j=1; j<k; ++j) m[i][j] = m[i][j-(j&-j)] + m[i][j&-j];

        for(int i=0; i<k; ++i)
            for(int j=0; (1<<j) <= i; ++j)
                if (i & (1<<j)) dp[i] = max(dp[i], dp[i^(1<<j)] - c[j] + m[j][i]);

        printf("Caso #%d: %d\n", t, dp[k-1]);
    }
    return 0;
}
