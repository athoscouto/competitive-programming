#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[1000], b[1000];
    int m = 0;

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf(" %1d", &a[i]);
    for(int i=0;i<n;i++) scanf(" %1d", &b[i]);
    for (int i =0; i<n;i++) m+=min(abs(a[i]-b[i]), 10 - abs(a[i]-b[i]));

    printf("%d\n", m);

    return 0;
}
