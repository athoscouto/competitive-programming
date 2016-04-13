#include <bits/stdc++.h>
using namespace std;

const int N = 8000;
int T, n, t=0, a[N], c[N], s1, s2, v[N], ns[N], k;

int dfs(int i) {
    v[i]++;
    if (v[a[i]]) {
        v[i]++;
        if (v[a[i]] == 2 or a[i] == i) return 0;
        ns[i] = 1;
        return a[i];
    }
    int x = dfs(a[i]);
    v[i]++;
    if (x) {
        ns[i] = 1;
        return x != i ? x : 0;
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        memset(c, 0, sizeof c);
        memset(ns, 0, sizeof ns);
        memset(v, 0, sizeof v);
        s1 = s2 = 0;

        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", a+i), c[a[i]]++;

        for(int i=1; i<=n; ++i) if (!v[i]) dfs(i);

        for(int i=1; i<=n; ++i) {
            s1 += (c[i] == 0);
            s2 += (ns[i] == 0);
        }
        printf("Caso #%d: %d %d\n", t, s1, s2);

    }
    return 0;
}
