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
        int L4 = 4 * L;
        int posi, posk;
        int strings_passed = 0;

        for (int i = 0; i < L; i++)
            scanf(" %c", letters + i);

        result = 0;
        sign = 1;
        for (int i = 0; i < L4; i++) {
            temp = int(letters[i % L] - 'h');
            sign *= signals[result][temp];
            result = value[result][temp];
            if (result == 1 && sign == 1) {
                strings_passed += i / L;
                flag1 = true;
                result = 0;
                posi = i % L;
                break;
            }
        }
        if (flag1 && strings_passed < X) {
            for (int i = posi + 1; i < L4 + posi + 1; i++){
                temp = int(letters[i % L] - 'h');
                sign *= signals[result][temp];
                result = value[result][temp];
                if (result == 2 && sign == 1) {
                    strings_passed += i / L;
                    flag2 = true;
                    result = 0;
                    posk = i % L;
                    break;
                }
            }
        }

        if (flag2 && strings_passed < X) {
            for (int i = posk + 1; i < L4; i++){
                temp = int(letters[i % L] - 'h');
                sign *= signals[result][temp];
                result = value[result][temp];
                if ((i % L == L - 1) && result == 3 && sign == 1) {
                    if ((strings_passed + (i + 1) / L - X) % 4 == 0) {
                        print = false;
                        printf("Case #%d: YES\n", test_case);
                        break;
                    }
                }
            }
        }


        if (print)
            printf("Case #%d: NO\n", test_case);
    }
    return 0;
}
