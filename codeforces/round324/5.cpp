#include <bits/stdc++.h>
using namespace std;

int n, p1[2010], p2[2010], inv1[2010], inv2[2010], sum;
vector<pair<int, int> > swps;

void slv(int posx, int y) {
    if (p1[posx] == y) return;
    int x = p1[posx], posy = inv1[y], tgtx  = inv2[x];
    if (tgtx < posx) {slv(tgtx, x); slv(posx, y); return;}
    if (tgtx < posy) {slv(tgtx, y); slv(posx, y); return;}
    p1[posx] = y, p1[posy] = x, inv1[y] = posx, inv1[x] = posy;
    swps.push_back(make_pair(posx, posy));
    sum += abs(posx - posy);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &p1[i]), inv1[p1[i]] = i;
    for(int i=1; i<=n; ++i) scanf("%d", &p2[i]), inv2[p2[i]] = i;
    sum=0;
    for(int i=1; i<=n; ++i) slv(i, p2[i]);
    printf("%d\n%d\n", sum, (int)swps.size());
    for(int i=0; i<swps.size(); ++i) printf("%d %d\n", swps[i].second, swps[i].first);
    return 0;
}
