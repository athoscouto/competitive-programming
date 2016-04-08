#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2, mod = 1e6;

ll n, k, l, b[N][N], m[N][N], v[N];

void mult(ll a[N][N], ll b[N][N]) {
    ll c[N][N];
    memset(c, 0, sizeof c);
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) for(int k=0; k<N; ++k)
        c[i][j] += a[i][k]*b[k][j], c[i][j] %= mod;

    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) a[i][j] = c[i][j];
}

void exp(ll b[N][N], ll e, ll r[N][N]) {
    while(e) {
        if (e%2) mult(r, b);
        mult(b, b);
        e /= 2;
    }
}

int main() {
    while(scanf("%lld%lld%lld", &n, &k, &l) != EOF) {
        memset(b, 0, sizeof b);
        memset(m, 0, sizeof m);
        memset(v, 0, sizeof v);

        k %= mod, l %= mod;

        b[1][0] = 1;
        b[0][0] = k;
        b[0][1] = l;

        m[0][0] = m[1][1] = 1;

        v[1] = 1;
        v[0] = k*v[1];

        exp(b, n/5-1, m);

        printf("%.6lld\n", (m[0][0]*v[0] + m[0][1]*v[1]) % mod);
    }
    return 0;
}
