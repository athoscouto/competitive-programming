#include <bits/stdc++.h>
using namespace std;

int n, c, s, x;
set<int> p;

int main() {
    while(scanf("%d", &n) != EOF) {
        p.clear();
        s = c = 0;
        for(int i=1; i<=n; ++i) scanf("%d", &x), p.insert(s), s += x;
        for(set<int>::iterator i = p.begin(); i != p.end(); ++i)
            c += p.count(*i + s/3) and p.count(*i + 2*s/3);
        printf("%d\n", s % 3 ? 0 : c);
    }
    return 0;
}
