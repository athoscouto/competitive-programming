#include <bits/stdc++.h>

using namespace std;

int value[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

int signals[4][4] = {
    {1,  1,  1,  1},
    {1, -1,  1, -1},
    {1, -1, -1,  1},
    {1,  1, -1, -1}
};



char letters[10000];

int main() {
    int T;
    scanf("%d", &T);

    for(int test_case = 1; test_case <= T; test_case++) {
        int X, L, result, sign, temp;
        bool print = true;
        bool flag1, flag2;
        flag1 = flag2 = false;

        scanf(" %d %d", &L, &X);
        int XL = X * L;

        for (int i = 0; i < L; i++)
            scanf(" %c", letters + i);

        result = 0;
        sign = 1;
        for (int i = 0; i < XL; i++) {
            temp = int(letters[i % L] - 'h');
            sign *= signals[result][temp];
            result = value[result][temp];
            if (!flag1 && result == 1) {
                flag1 = true;
                result = 0;
            } else if (!flag2 && flag1 && result == 2) {
                flag2 = true;
                result = 0;
            } else if (flag2 && result == 3 && sign == 1) {
                printf("Case #%d: YES\n", test_case);
                print = false;
                break;
            }
        }

        if (print)
            printf("Case #%d: NO\n", test_case);
    }
    return 0;
}
