#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    int test = 1;

    while (scanf("%d %d", &n, &m) && (m || n)) {
        char field[n][m];
        char buffer;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                field[i][j] = '0';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &buffer);
                if (buffer == '*') {
                    field[i][j] = '*';

                    for (int k = i - 1; k <= i + 1; k++)
                        for (int l = j - 1; l <= j + 1; l++)
                            if (k >= 0 && l >= 0 && k <= n && l <= m)
                                if (field[k][l] != '*')
                                    field[k][l] = int(field[k][l]) + 1;
                }
            }
        }
        printf("Field #%d:\n", test++);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%c", field[i][j]);
            printf("\n");
        }

    }
    return 0;
}
