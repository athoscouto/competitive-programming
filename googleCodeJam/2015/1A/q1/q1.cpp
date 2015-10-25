#include <bits/stdc++.h>

using namespace std;

int M[10001];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n;
        scanf(" %d", &n);

        for(int i = 0; i < n; i++)
            scanf(" %d", &M[i]);

        int y = 0;
        int temp;
        int max = 0;
        for(int i = 1; i < n; i++) {
            temp = M[i-1] - M[i];
            if (temp > 0) y += temp;
            if (temp > max) max = temp;
        }
        int z = 0;
        for (int i = 0; i < n -1; i++)
            z += min(M[i], max);

        printf("Case #%d: %d %d\n", t, y, z);
    }

    return 0;
}
