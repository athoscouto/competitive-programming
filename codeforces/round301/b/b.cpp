#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, p, x, y, ones, left, ys, g, sum, h;
    h=sum=0;
    scanf(" %d %d %d %d %d", &n, &k, &p, &x, &y);
    for(int i =0; i<k;i++) {scanf(" %d", &g); sum += g; if (g>=y) h++; else h--;}
    if (n - k + sum > x) {printf("-1\n"); return 0;}
    if (y==1){ for(int i=0;i<n-k;i++) printf("1 "); printf("\n"); return 0;}
    left = min(x-sum, (n-k)*p) - n + k; ys = min(left / (y-1), n-k); ones = n - k - ys; h += ys - ones;
    if (h<0) {printf("-1\n"); return 0;}
    for (int i=0;i<ones;i++) printf("1 ");
    for (int i=0;i<ys;i++) printf("%d ", y);
    printf("\n");
    return 0;
}
