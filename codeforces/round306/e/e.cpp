#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, v[100000];
    scanf("%d", &n);

    for(int i=0; i<n; ++i) scanf("%d", &v[i]);

    if (v[n-1] == 1) {printf("NO\n"); return 0;}
    if (n==1) {printf("YES\n0\n"); return 0;}

    if (v[n-2] == 1) {
        printf("YES\n");
        for(int i=0; i<n-1; i++) printf("%d->", v[i]);
        printf("%d\n", v[n-1]);
        return 0;
    }

    if (n==2) {printf("NO\n"); return 0;}

    if (v[n-3] == 0) {
        printf("YES\n");
        for(int i=0; i<n-3; i++) printf("%d->", v[i]);
        printf("(0->0)->0\n");
        return 0;
    }

    bool z = false; int zero;
    for(int i=n-4; i>=0; --i)
        if (v[i]==0) {z = true; zero = i; break;}

    if (!z) {printf("NO\n"); return 0;}

    printf("YES\n");
    for(int i=0; i<n-1;++i)
        if (i == zero) printf("(0->(");
        else if (i == n-2) printf("0))->");
        else printf("%d->", v[i]);
    printf("0\n");

    return 0;
}
