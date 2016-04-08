#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5+1, lgN = 20, INF = 1e9;

int n, m, s, u, v, x, vst[N], anc[N][lgN], mn[N][lgN], h[N];
vector<ii> g[N];
priority_queue<iii> q;

void prim() {
    vst[1] = 1;
    anc[1][0] = 1;
    mn[1][0] = INF;
    for(int i=0; i<g[1].size(); ++i) q.push(iii(g[1][i].f, ii(1, g[1][i].s)));

    while(!q.empty()) {
        int u = q.top().s.f, v = q.top().s.s, w = q.top().f; q.pop();
        if (vst[v]) continue;
        vst[v] = 1;
        h[v] = h[u] + 1;
        anc[v][0] = u;
        mn[v][0] = w;

        for(int i=0; i<g[v].size(); ++i) q.push(iii(g[v][i].f, ii(v, g[v][i].s)));
    }
}

int calc_min(int u, int v) {
    int ans = INF;
    if (h[u] < h[v]) swap(u, v);

    for(int i=lgN-1; i >= 0; --i)
        if (h[u] - h[v] >= (1<<i))
            ans = min(ans, mn[u][i]), u = anc[u][i];

    if (u == v) return ans;

    for(int i=lgN-1; i>=0; --i) if (anc[u][i] != anc[v][i]) {
        ans = min(ans, min(mn[u][i], mn[v][i]));
        u = anc[u][i];
        v = anc[v][i];
    }

    return min(ans, min(mn[v][0], mn[u][0]));
}

int main() {
    while(scanf("%d%d%d", &n, &m, &s) != EOF) {
        for(int i=1; i<=n; ++i) g[i].clear(), vst[i] = 0;
        for(int i=0; i<m; ++i) {
            scanf("%d%d%d", &u, &v, &x);
            g[u].pb(ii(x,v)), g[v].pb(ii(x,u));
        }

        prim();

        for(int j=1; j<lgN; ++j) {
            for(int i=1; i <= n; ++i) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                mn[i][j] = min(mn[anc[i][j-1]][j-1], mn[i][j-1]);
            }
        }

        for(int i=0; i<s; ++i) {
            scanf("%d%d", &u, &v);
            printf("%d\n", calc_min(u, v));
        }
    }
    return 0;
}
