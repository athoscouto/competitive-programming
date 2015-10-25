#include <bits/stdc++.h>
using namespace std;

void solve() {
    int  A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    for(int z=-97; z<100; ++z) for(int y=-98; y<z; ++y) for(int x=-99; x<y; ++x)
        if(x*x+y*y+z*z == C && x*y*z == B && x+y+z == A) {
            printf("%d %d %d\n", x, y, z);
            return;
        }
    printf("No solution.\n");
}
int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        solve();
    }
    return 0;
}
