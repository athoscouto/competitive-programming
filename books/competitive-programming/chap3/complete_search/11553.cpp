#include <bits/stdc++.h>
using namespace std;

int t, n, M[10][10], v[8], sum, msum;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int j=0; j<n; ++j) for(int i=0; i<n; ++i) scanf("%d", &M[i][j]);

        msum = 99999999;
        for(int i=0; i<n; ++i) v[i]=i;
        do {
            sum=0; for(int i=0; i<n; ++i) sum += M[i][v[i]];
            msum = min(sum, msum);
        } while(next_permutation(v, v+n));
        printf("%d\n", msum);
    }
    return 0;
}
