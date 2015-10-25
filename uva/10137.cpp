#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while(scanf("%d", &n) && n) {
        int costs[n];
        int c1, c2;
        int exchange = 0, media = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d.%d", &c1, &c2);
            costs[i] = c1 * 100 + c2;
            media += costs[i];
        }

        int rest = media % n;
        media /= n;

        for (int i = 0; i < n; i++) {
            if (costs[i] > media) {
                exchange += costs[i] - media;
                if (rest) {
                    rest --; exchange --;
                }
            }
        }

        printf("$%d.%02d\n", exchange / 100, exchange % 100);
    }
    return 0;
}
