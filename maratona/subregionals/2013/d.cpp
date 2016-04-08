#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, m, a[N], b[N];

bool slv(int n, int a[N]) {
    int c[N];

    if (n == m) {
        bool ok1 = 1, ok2 = 1;
        for(int i=0; i<n; ++i) if (a[i] != b[i]) ok1 = 0;
        for(int i=0; i<n; ++i) if (a[i] != b[n-i-1]) ok2 = 0;
        if (ok1 | ok2) return 1;
    }

    for(int i=1; i <= n - m and n >= 2*i; ++i) {
        for(int j=0; j < n-i; ++j) c[j] = a[j];
        for(int j=0; j < i; ++j) c[n-i-1-j] += a[n-i+j];
        if (slv(n-i, c)) return 1;

        for(int j=i; j < n; ++j) c[j-i] = a[j];
        for(int j=0; j < i; ++j) c[i-j-1] += a[j];
        if (slv(n-i, c)) return 1;
    }
    return 0;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; ++i) scanf("%d", a+i);
        scanf("%d", &m);
        for(int i=0; i<m; ++i) scanf("%d", b+i);
        printf("%c\n", slv(n, a) ? 'S' : 'N');
    }
    return 0;
}
