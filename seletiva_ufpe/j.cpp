#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int t, T, n, n0, c, m[N][N], id[N], s[N], ans, aux[N][N];

bool cp(int i, int j) {return s[i] < s[j];}

int main() {
    scanf("%d", &T);
    while (t++ < T) {
        ans = 0;
        scanf("%d", &n0);
        for(int i=0; i<n0; ++i) scanf("%d", &c), ans -= c;
        for(int i=0; i<n0; ++i) for(int j=0; j<n0; ++j) scanf("%d", &m[i][j]);

        for(n=n0; n>1; --n) {
            memset(s, 0, sizeof s);
            for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) s[i] += m[i][j] - m[j][i];

            for(int i=0; i<n; ++i) id[i] = i;
            sort(id, id+n, cp);

            for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) aux[i][j] = m[i][j];
            for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) m[i][j] = aux[id[i]][id[j]];
        }

        for(int i=0; i<n0; ++i) for(int j=0; j<i; ++j) ans += m[i][j];

        printf("Caso #%d: %d\n", t, ans);
    }
    return 0;
}
