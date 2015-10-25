#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int v[100];
    for(int i=0; i<n; ++i) scanf("%1d", &v[i]);
    bool dp[100][8];
    dp[0][v[0]%8] = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<8; j++) {
            dp[i][(dp[i-1][j]*10 + v[i]) % 8] = true;
        }
    }
    return 0;
}
