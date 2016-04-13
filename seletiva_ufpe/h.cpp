#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int S = 21, N = 1e5+1, INF = 1e9+1;
int T, t, y, n, k, u, v, w, d[N];
char s[S];
vector<ii> g[N];
map<string, int> mp;
priority_queue<ii, vector<ii>, greater<ii> > q;

int dijkstra() {
    q.push(ii(0, 1));

    while(!q.empty()) {
        int u = q.top().second, t = q.top().first; q.pop();
        if (t >= d[u]) continue;
        if (u == 2) return t;
        d[u] = t;

        for(int i=0; i<g[u].size(); ++i) {
            int v = g[u][i].second, x = g[u][i].first, tv = y + t + (t % x != 0)*(x - t%x);
            if (tv < d[v]) q.push(ii(tv, v));
        }
    }
    return -1;
}

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        mp.clear();
        for(int i=0; i<N; ++i) g[i].clear(), d[i] = INF;
        k = 1;

        scanf(" %s", s), mp[s] = k++;
        scanf(" %s", s), mp[s] = k++;
        scanf("%d%d", &y, &n);

        for(int i=0; i<n; ++i) {
            scanf(" %s", s);
            if (!mp[s]) mp[s] = k++;
            u = mp[s];
            scanf(" %s", s);
            if (!mp[s]) mp[s] = k++;
            v = mp[s];
            scanf("%d", &w);
            g[u].push_back(ii(w, v));
        }

        w = dijkstra();

        if (w > -1) printf("Caso #%d: %d anticalmas\n", t, w);
        else printf("Caso #%d: Destino inalcancavel\n", t);

        while(!q.empty()) q.pop();
    }
    return 0;
}
