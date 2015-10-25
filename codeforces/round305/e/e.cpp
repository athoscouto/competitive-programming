#include <bits/stdc++.h>

using namespace std;

int a[200001];
set<int> shelf;
set<int>::iterator it, it2;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {

    int n, q, x;
    long long ls = 0;
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=0; i<q; i++) {
        scanf("%d", &x);

        long long score = 0;
        for(it=shelf.begin(); it!=shelf.end(); ++it) {
            if (*it == x) continue;
                else score += gcd(a[*it], a[x]) == 1 ? 1 : 0;
            }

        if (shelf.find(x) != shelf.end()) {shelf.erase(x); ls -= score;}
        else {shelf.insert(x); ls += score;}

        printf("%lld\n", ls);
    }
    return 0;
}
