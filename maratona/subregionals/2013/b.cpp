#include <bits/stdc++.h>
#define y1 asdfg
using namespace std;

const int N = 1e6+1;
int n, c, xs[N], ys[N], xe[N], ye[N], x1, x2, y1, y2, ids[N], ide[N], nxt[N], nxtx[N], fs[N], fx[N], vst[N], s, e, x;

bool cps(int i, int j) {return xs[i] < xs[j] or (xs[i] == xs[j] and ys[i] > ys[j]);}
bool cpe(int i, int j) {return xe[i] < xe[j] or (xe[i] == xe[j] and ye[i] < ye[j]);}

bool scp(int i, int j) {
    if (xs[i] < xs[j]) return 1ll*(xe[i] - xs[i]) * (ys[j] - ys[i]) > 1ll*(ye[i] - ys[i]) * (xs[j] - xs[i]);
    else return 1ll*(xe[j] - xs[j]) * (ys[i] - ys[j]) < 1ll*(ye[j] - ys[j]) * (xs[i] - xs[j]);
}

set<int, bool (*)(int, int)> seg(scp);

void dfs(int u) {
    vst[u] = 1;
    int v = nxt[u];
    if (v == -1) {nxt[u] = u, nxtx[u] = -1; return;}
    if (!vst[v]) dfs(v);
    nxt[u] = nxt[v];
    if (v != nxt[v]) nxtx[u] = nxtx[v];
}

int main() {
    while(scanf("%d%d", &n, &c) != EOF) {
        seg.clear();
        memset(nxt, -1, sizeof nxt);
        memset(nxtx, -1, sizeof nxtx);
        memset(vst, 0, sizeof vst);

        for(int i=0; i<n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) swap(y2, y1), swap(x2, x1);
            xs[i] = x1, ys[i] = y1, ids[i] = i;
            xe[i] = x2, ye[i] = y2, ide[i] = i;
        }

        ids[n] = ide[n] = n;
        xs[n] = -1, ys[n] = 1e6+1;
        xe[n] = 1e6+1, ye[n] = 1e6+1;
        n++;
        sort(ids, ids+n, cps), sort(ide, ide+n, cpe);

        s = e = 0;
        for(x=0; x<1e6+1; ++x) {
            for(int j = ids[s]; s < n and xs[j] <= x; j = ids[++s]) {
                seg.insert(j);
                if (ys[j] > ye[j]) nxt[j] = *(++seg.find(j)), nxtx[j] = xs[j];
            }

            fs[x] = *seg.begin();

            for(int k = ide[e]; e < n and xe[k] <= x; k = ide[++e]) {
                if (ys[k] < ye[k]) nxt[k] = *(++seg.find(k)), nxtx[k] = xe[k];
                seg.erase(k);
            }
        }

        for(int i=0; i<n; ++i) if (!vst[i]) dfs(i);

        for(x=0; x<1e6+1; ++x) {
            fx[x] = (nxt[fs[x]] == fs[x]) ? x : nxtx[fs[x]];
            fs[x] = nxt[fs[x]];
        }

        for(int i=0; i<c; ++i) {
            scanf("%d", &x);
            if (fs[x] != n-1) printf("%d %d\n", fx[x], ys[fs[x]]);
            else printf("%d\n", fx[x]);
        }
    }
    return 0;
}
