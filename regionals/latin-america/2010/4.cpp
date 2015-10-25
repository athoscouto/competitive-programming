#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int a, b, m, va[10], vb[10], dgs[10], prefix, suffix;

void slv(int n, int *vn) {
    m = 0; memset(vn, 0, sizeof vn);
    while(n) dgs[m] = n%10, n/=10, ++m;
    for(int i=0; i<m; ++i) {
        suffix = prefix = 0;
        for(int j=0; j<i; ++j) suffix += dgs[j] * pow(10, j);
        for(int j=i+1; j<m; ++j) prefix += dgs[j] * pow(10, j-i-1);
        for(int j=0; j<10; ++j) vn[j] += (prefix + (dgs[i] > j) - (j==0))*pow(10, i) + (j==dgs[i])*(suffix+1);
    }
}

int main() {
    while(scanf("%d %d", &a, &b) && (a || b)) {
        memset(vb, 0, sizeof vb), memset(va, 0, sizeof va);
        slv(a-1, va), slv(b, vb);
        for(int i=0; i<9; ++i) printf("%d ", vb[i] - va[i]);
        printf("%d\n", vb[9] - va[9]);
    }
    return 0;
}
