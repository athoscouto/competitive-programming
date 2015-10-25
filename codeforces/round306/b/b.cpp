#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, l, r, x;
    int c[15]; 
    scanf("%d %d %d %d", &n, &l, &r, &x);

    for(int i=0; i<n; i++) scanf("%d", &c[i]);

    int num = 1 << n;
    int cc = 0;
    for(int i=0; i<num; i++) {
        int sum=0;
        int m=999999, M=0;
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) {
                m = m < c[j] ? m : c[j];
                M = M > c[j] ? M : c[j];
                sum += c[j];
            }
        }
        if (sum >= l && sum <= r && (M-m) >= x) cc++;
    }

    printf("%d\n", cc);
    return 0;
}
