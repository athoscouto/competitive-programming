#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (scanf("%d", &n) && n) {
        int x, y, a, b;

        scanf("%d %d", &x, &y);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);

            if (x == a || y == b)
                printf("divisa\n");
            else if (a > x) {
                if (b > y)
                    printf("NE\n");
                else
                    printf("SE\n");
            }
            else {
                if (b > y)
                    printf("NO\n");
                else
                    printf("SO\n");
            }
        }
    }
    return 0;
}
