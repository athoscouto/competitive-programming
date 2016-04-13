#include <bits/stdc++.h>
using namespace std;

const int N = 200, X = 300;
int T, t, n, m, g, x, k[N], v[N][N], dp[N][X][N], r;

int slv(int a, int b, int c) {
    if (b > x or c > m) return -1;
    if (a == g or c == m) return b;
    if (dp[a][b][c] > -1) return dp[a][b][c];

    int M = max(b, slv(a+1, b, c));
    for(int i=0; i<k[a]; ++i) M = max(M, slv(a+1, b+v[a][i], c+1));

    return dp[a][b][c] = M;
}

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        memset(dp, -1, sizeof dp);
        scanf("%d%d%d%d", &n, &m, &g, &x);
        for(int i=0; i<g; ++i) {
            scanf("%d", k+i);
            for(int j=0; j<k[i]; ++j) scanf("%d", &v[i][j]);
        }

        printf("Caso #%d: %d\n", t, slv(0, 0, 0));

    }
    return 0;
}
