#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, n, l, t, m, r;

    scanf("%d %d %d", &A, &B, &n);

    for(int i = 0; i < n; i++) {
        scanf(" %d %d %d", &l, &t, &m);

        if (A + (l - 1) * B > r) {
            printf("-1\n");
            continue;
        }


        
    }
    return 0;
}
