#include <bits/stdc++.h>

using namespace std;

int main() {

    int k, n, m;
    scanf("%d", &k);

    if (k == 1) { printf("YES\n2 1\n1 2\n"); return 0;}
    if (k % 2 == 0) {printf("NO\n"); return 0;}

    n = 2*k+4; m = (k+1)*k+k;

    printf("YES\n%d %d\n", n, m);
    for(int i=1; i<=k+1; i++) for(int j=i+1; j<=k+1; j++)
        if (i<=(k-1)/2 && i==k+2-j) continue;
        else printf("%d %d\n", i, j);

    for(int i=1; i<=(k-1)/2; i++) {printf("%d %d\n", i, k+2); printf("%d %d\n", k+2-i, k+2);}

    printf("%d %d\n", k+2, k+3);

    for(int i=1; i<=(k-1)/2; i++) {printf("%d %d\n", i+k+3, k+3); printf("%d %d\n", 2*k+5-i, k+3);}

    for(int i=1; i<=k+1; i++) for(int j=i+1; j<=k+1; j++)
        if (i<=(k-1)/2 && i==k+2-j) continue;
        else printf("%d %d\n", i+k+3, j+k+3);

    return 0;
}
