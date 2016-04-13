#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int T, t, n, x, m, v[N], a, b;
char c;

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        scanf("%d%d%d", &n, &x, &m);
        for(int i=1; i<=n; ++i) scanf("%d", v+i);
        for(int i=1; i<=n; ++i) {
            scanf(" %c", &c);
            v[i] = (c == '1' and v[i] < x);
        }

        for(int i=2; i<=n; ++i) v[i] += v[i-1];
        printf("Caso #%d:\n", t);
        for(int i=0; i<m; ++i) {
            scanf("%d%d", &a, &b);
            printf("%d\n", v[b]-v[a-1]);
        }
    }
    return 0;
}
