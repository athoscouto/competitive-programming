#include <bits/stdc++.h>
using namespace std;

int main () {
    int nums[1000], q;
    vector<int> sums;
    sums.resize(1000000);
    int n, m;
    int C=1;

    while(scanf("%d", &n) && n!=0) {
        printf("Case %d:\n", C++);
        int k=0;
        for (int i=0; i<n; ++i) {
            scanf("%d", &nums[i]);
            for(int j=0; j<i; j++)
                sums[k++] = nums[i] + nums[j];
        }
        sort(sums.begin(), sums.begin()+k);
        scanf("%d", &m);
        for(int i=0; i<m; ++i) {
            scanf("%d", &q);
            int l=0, r=k-1, mi;
            while(r-l>1) {
                mi = (l+r)/2;
                if (sums[mi] < q) l = mi;
                else r = mi;
            }
            if (abs(q - sums[l]) <= abs(q - sums[r]))
                printf("Closest sum to %d is %d.\n", q, sums[l]);
            else
                printf("Closest sum to %d is %d.\n", q, sums[r]);
        }

    }
    return 0;

}
