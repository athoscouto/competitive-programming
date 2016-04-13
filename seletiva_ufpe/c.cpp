#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
int t, T, n, m, a[N][N], b[N][N], ans, mx;
vector<int> x[N], y[N];
char c;

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        scanf("%d%d", &n, &m);

        memset(b, 0, sizeof b);
        memset(a, 0, sizeof a);
        for(int i=1; i<=m; ++i) y[i].clear(), x[i].clear();
        ans = mx = 0;

        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
            scanf(" %c", &c);
            if (c == 'C') {
                a[i][j] = 1 + a[i][j-1];
                x[a[i][j]].push_back(j);
                y[a[i][j]].push_back(i);
            }
        }

        for(int i=m; i>0; --i) {
            for(int j=0; j<x[i].size(); ++j) {
                int l = x[i][j], k = y[i][j];
                b[k][l] = b[k+1][l] + b[k-1][l] + 1;
                b[k+b[k+1][l]][l] = b[k-b[k-1][l]][l] = b[k][l];
                mx = max(mx, b[k][l]);
            }
            ans += mx;
        }

        printf("Caso #%d: %d\n", t, ans);
    }
    return 0;
}
