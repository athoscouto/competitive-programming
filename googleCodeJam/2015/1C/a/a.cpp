#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for(int t=1;t<=T;t++) {
        int R, C, W;
        scanf("%d %d %d", &R, &C, &W);
        int ans = (C / W) * R + W;
        if (C%W == 0) ans--;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
