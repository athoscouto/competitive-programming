#include <bits/stdc++.h>

using namespace std;

int to_int(char c) {
    return int(c - '0');
}

int main() {
    int T;
    scanf("%d", &T);

    for(int test_case = 1; test_case <= T; test_case++) {
        char shyness[1001];
        int S;
        scanf(" %d", &S);

        for(int i = 0; i <= S; i++)
            scanf(" %c", &shyness[i]);

        int standing = to_int(shyness[0]);
        int invited = 0;

        for (int i = 1; i <=S; i++) {
            if (standing < i) {
                invited += i - standing;
                standing = i + to_int(shyness[i]);
            } else {
                standing += to_int(shyness[i]);
            }
        }

        printf("Case #%d: %d\n", test_case, invited);

    }
    return 0;
}
