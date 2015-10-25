#include <bits/stdc++.h>

using namespace std;

int plates[1000];
int D;

int num_special_times(int max) {
    int num = 0;

    for (int i = 0; i < D; i++) {
        num += plates[i] / max;
        if (!(plates[i] % max))
            num--;
    }
    return num;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf(" %d", &D);

        for (int i = 0; i < D; i++)
            scanf(" %d", &plates[i]);

        int max_el = *max_element(plates, plates + D);
        int min = max_el;
        int num_moves, imin = -1;

        for (int i = max_el; i > 1; i--){
            if ((num_moves = i + num_special_times(i)) < min) {
                min = num_moves;
                imin = i;
            }
        }

        printf("Case #%d: %d\n", t, min);
    }
    return 0;
}
