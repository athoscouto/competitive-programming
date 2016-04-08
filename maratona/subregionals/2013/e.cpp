#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int n, r, x, v[N];

int main() {
    while(scanf("%d%d", &n, &r) != EOF) {
        memset(v, 0, sizeof v);
        for(int i=0; i<r; ++i) scanf("%d", &x), v[x] = 1;
        if (n != r) {
            for(int i=1; i<=n; ++i) if (!v[i]) printf("%d ", i);
        } else printf("*");
        printf("\n");
    }
    return 0;
}
