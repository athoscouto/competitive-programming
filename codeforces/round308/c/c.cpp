#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n;
    scanf("%d %d", &w, &n);
    int i = -1;

    while(n>0)
        if (++i <= 100)
            if (n%w == 0) n /= w;
            else if (n%w == 1) n = (n-1)/w;
            else if (n%w == w-1) n = (n+1)/w;
            else {printf("NO\n"); return 0;}
        else {printf("NO\n"); return 0;}
    printf("YES\n");
    return 0;
}
