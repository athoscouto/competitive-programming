#include <bits/stdc++.h>
using namespace std;

const int N = 501, INF=1e9+1;
int n, m, I, ag[N], x, y, vst[N], g[N][N], pst[N], ppl[N], mag;
char c;

void dfs(int u) {
    vst[u] = 1;

    for(int v=1; v<=n; ++v) if (g[u][v] and !vst[v]) dfs(v);
    for(int v=1; v<=n; ++v) if (g[u][v]) for(int i=1; i<=n; ++i) g[u][i] |= g[v][i];
}

int main() {
    while(scanf("%d%d%d", &n, &m, &I) != EOF) {
        memset(vst, 0, sizeof vst);

        for(int i=1; i<=n; ++i) {
            pst[i] = ppl[i] = i;
            for(int j=1; j<=n; ++j) g[i][j] = 0;
        }

        for(int i=1; i<=n; ++i) scanf("%d", ag+i);
        for(int i=0; i<m; ++i) scanf("%d%d", &x, &y), g[y][x] = 1;

        for(int i=1; i<=n; ++i) dfs(i);

        for(int i=0; i<I; ++i) {
            scanf(" %c", &c);
            if (c == 'T') {
                scanf("%d %d", &x, &y);
                swap(ppl[x], ppl[y]);
                swap(pst[ppl[x]], pst[ppl[y]]);
            } else {
                mag = INF;
                scanf("%d", &x);

                for(int i=1; i<=n; ++i) if(g[ppl[x]][i]) mag = min(mag, ag[pst[i]]);

                if (mag != INF) printf("%d\n", mag);
                else printf("*\n");
            }
        }
    }
    return 0;
}
