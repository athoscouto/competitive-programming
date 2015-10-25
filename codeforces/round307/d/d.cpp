#include <bits/stdc++.h>

using namespace std;


long long quick_exp(long long n, long long m) {
    long long bas = 2, re=1;
    while (n > 0)
        if (n % 2) {--n; re = (re * bas) % m;}
        else {n/=2; bas = (bas*bas)%m;}
    return re;
}

int main() {

    long long n, k, l, m, ans=1;

    scanf("%lld %lld %lld %lld", &n, &k, &n, &m);

    for (int i=0; i<l-1; ++i) {
        long long bit = 1<i;
        long long mult;
        if (k & bit) {
             mult = quick_exp(n-1, m) - 1;
             mult %= m;
        } else {
            mult = quick_exp(n-1, m) + 1;
            mult %= m;
        }
        ans = (ans*mult) % m;
    }

    printf("%lld\n", ans);

    return 0;
}
