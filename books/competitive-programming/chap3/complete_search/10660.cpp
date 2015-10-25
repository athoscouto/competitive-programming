#include <bits/stdc++.h>
using namespace std;

int pop[5][5], dist[5][5];
int T, m;
int x, y, v, min_val;
int offices[5];
int min_offices[5] = {0, 0, 0, 0, 0};

void solve() {
    for(x=0; x<5; ++x) for(y=0; y<5; ++y)
        dist[x][y] = 111111;
    int xo, yo, val=0;
    for(int i=0; i<5; ++i) {
        xo = offices[i] / 5; yo = offices[i] % 5;
        for(x=0; x<5; ++x) for(y=0; y<5; ++y)
            dist[x][y] = min(dist[x][y], abs(x-xo)+abs(y-yo));
    }
    for(x=0; x<5; ++x) for(y=0; y<5; ++y)
        val += dist[x][y]*pop[x][y];
    if (val < min_val) {
        min_val = val;
        for(int i=0; i<5; ++i) min_offices[i] = offices[i];
    }
}

void cs(int s, int k) {
    if (k == 0) {
        solve();
        return;
    }
    for(int i=s; i < 25-k+1; ++i) {
        offices[5-k] = i;
        cs(i+1, k-1);
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        min_val = 11111111;
        memset(pop, 0, 25*sizeof(int));
        scanf("%d", &m);
        for(int i=0; i<m; ++i) {scanf("%d %d %d", &x, &y, &v); pop[x][y] = v;}
        cs(0, 5);
        for(int i=0; i<5; ++i) {printf("%d", min_offices[i]); if (i!=4) printf(" ");}
        printf("\n");
    }
    return 0;
}
