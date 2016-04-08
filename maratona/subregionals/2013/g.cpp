#include <bits/stdc++.h>
using namespace std;

const int N = 301;
int l, c, m[N][N], k, ok, v[N];

int main() {
    while(scanf("%d%d", &l, &c) != EOF) {
        k = 0;
        ok = 1;

        for(int i=1; i<=l; ++i)
            for(int j=1; j<=c; ++j)
                scanf("%d", &m[i][j]);

        for(int j=1; j<=c; ++j)
            for(int i=1; i<=l; ++i)
                if (m[i][j] % c != m[1][j] % c) ok = 0;

        for(int i=1; i<=l; ++i)
            for(int j=1; j<=c; ++j)
                if (m[i][j]/c + (m[i][j]%c != 0) != m[i][1]/c + (m[i][1]%c != 0)) ok = 0;

        if (!ok) printf("*\n");
        else {
            for(int i=1; i<=c; ++i) v[i-1] = m[1][i];
            for(int i=0; i<c; ++i) if (v[i] % c != (i+1) % c) swap(v[i], v[(v[i]-1) % c]), k++, i--;
            for(int i=1; i<=l; ++i) v[i-1] = m[i][1];
            for(int i=0; i<l; ++i) if (v[i]/c - (v[i]%c == 0) != i) swap(v[i], v[v[i]/c - (v[i]%c == 0)]), k++, i--;

            printf("%d\n", k);
        }
    }
    return 0;
}
