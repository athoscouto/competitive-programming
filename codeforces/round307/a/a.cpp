#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int a[2001];
    int b[2001];
    int c[2001];
    for(int i=0; i<2001; ++i) c[i]=b[i]=0;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {scanf("%d", &a[i]); b[a[i]]++;}
    c[2000] = 1;
    for(int i=1999; i>=1; --i) {c[i] = c[i+1]+b[i+1];}
    for(int i=1; i<=n; ++i) {printf("%d ", c[a[i]]);}
    printf("\n");

    return 0;
}
