#include <bits/stdc++.h>
using namespace std;

const int T=1e7, Q=10;
int t, q, st[Q], end[Q], lt;
bool tele[2*T+2];

int main() {
    while(scanf("%d %d", &t, &q) && (q || t)) {
        memset(tele, 0, sizeof tele);
        for(int i=0; i<t; ++i) scanf("%d", &lt), tele[lt+T] = 1;
        for(int i=0; i<q; ++i) scanf("%d %d", &st[i], &end[i]), st[i]+=T, end[i]+=T;
        for(int i=0, lt=0; i<=2*T+1; ++i) if (tele[i]) {
            if (2*i-lt <= 2*T+1) tele[2*i-lt] = 1;
            lt = i;
            for(int j=0; j<q; ++j) {
                if (st[j] < i) st[j] = 2*i - st[j];
                if (end[j] < i) end[j] = 2*i - end[j];
            }
        }
        for(int i=0; i<q; ++i) printf("%c%c", st[i] == end[i] ? 'Y' : 'N', i<(q-1) ? ' ' : '\n');
    }
    return 0;
}
