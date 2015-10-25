#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9, mod=1e8;

int dp[210][210];
vector<pair<int, int> > act;
vector<int> t;
int m, n;

int slv(int l, int r) {
    if (dp[l][r] > -1) return dp[l][r];
    if (r == m) return dp[l][r] = 1;
    dp[l][r] = 0;
    for(int i=0; i<n; ++i)
        if ((act[i].first > r) || (act[i].first < l) || (act[i].second <= r)) continue;
        else dp[l][r] = (dp[l][r] + slv(r+1, act[i].second)) % mod;
    return dp[l][r];
}

int main() {
    int st, ed;
    while(cin >> m >> n && (m || n)) {
        t.clear(); act.clear();
        for(int i=0; i<210; ++i) for(int j=0; j<210; ++j) dp[i][j] = -1;
        for(int i=0; i<n; ++i) {
            cin >> st >> ed;
            act.push_back(make_pair(st, ed));
            t.push_back(st); t.push_back(ed);
        }
        sort(act.begin(), act.end()); sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());

        if (t[t.size()-1] == m) m = t.size()-1;
        for(int i=0, j; i < act.size(); ++i) {
            j=0;
            while (act[i].first != t[j]) j++;
            act[i].first = j;
            while (act[i].second != t[j]) j++;
            act[i].second = j;
        }

        if (t[0] == 0) printf("%d\n", slv(0, 0));
        else printf("0\n");
    }
    return 0;
}
