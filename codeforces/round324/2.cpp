#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mod = 1e9+7;
    long long ans = 1, bns = 1;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        bns *= 7; ans *= 27;
        ans %= mod; bns %= mod;
    }
    printf("%lld\n", (ans-bns >= 0) ? (ans-bns) : (mod+ans-bns));
    return 0;
}
