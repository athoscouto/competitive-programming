#include <bits/stdc++.h>

using namespace std;

int v1[1111111], v2[1111111];

int main() {

    long long m, h1, a1, x1, y1, h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);

    int  c = 0;
    while(!v1[h1]) {
        v1[h1] = ++c;
        h1 = (x1*h1+y1) % m;
    }
    c = 0;
    while(!v2[h2]) {
        v2[h2] = ++c;
        h2 = (x2*h2+y2) % m;
    }

    if(v1[a1] == 0 || v2[a2] == 0) printf("-1\n");
    else {
        printf("%lld\n", 1ll*(v1[a1]-1)*(v2[a2]-1)/__gcd(v1[a1]-1,v2[a2]-1));
    }

    return 0;
}
