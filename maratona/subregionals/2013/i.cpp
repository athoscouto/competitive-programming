#include <bits/stdc++.h>
using namespace std;

const int N = 1001, INF = 1e9;
int n, c, dp[N], t1, t2, d[N], ans;

int main() {
    while(scanf("%d%d%d%d", &n, &c, &t1, &t2) != EOF) {
        for(int i=0; i<n; ++i) scanf("%d", d+i);
        for(int i=n-1; i>=0; --i) d[i] -= d[0];
        ans = d[n] = INF;

        for(int k=0; k<n; ++k) {
            for(int i=0; i<n+1; ++i) dp[i] = INF;
            dp[0] = 0;

            for(int i=0; i<n; ++i) {
                int j = upper_bound(d, d+n+1, d[i] + t1) - d;
                dp[j] = min(dp[i] + t1, dp[j]);

                j = upper_bound(d, d+n+1, d[i] + t2) - d;
                dp[j] = min(dp[i] + t2, dp[j]);
            }
            ans = min(ans, dp[n]);

            int x = d[1];
            for(int i=0; i<n-1; ++i) d[i] = d[i+1] - x;
            d[n-1] = c - x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
