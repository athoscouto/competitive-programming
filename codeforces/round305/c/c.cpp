#include <bits/stdc++.h>

using namespace std;

int main() {

    long long m, h1, a1, x1, y1, h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);

    long long  c = 0;
    while(h1 != a1 || h2 != a2) {
        h1 = (x1*h1+y1) % m;
        h2 = (x2*h2+y2) % m;
        c++;
        if (c > 9999999) {printf("-1\n"); return 0;}
    }

    printf("%lld\n", c);

    return 0;
}
