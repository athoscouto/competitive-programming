#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x1, x2, y1, y2, sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sum += (abs(x1-x2)+1)*(abs(y1-y2)+1);
    }
    printf("%d\n", sum);
    return 0;
}
