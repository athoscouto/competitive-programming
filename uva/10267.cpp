#include <bits/stdc++.h>

using namespace std;

char image[250][250];

void searchNpaint(char color, int x, int y, int m, int n) {
    char old_color = image[x][y];
    image[x][y] = color;
    if (x > 0 && old_color == image[x - 1][y])
        searchNpaint(color, x - 1, y, m, n);
    if (y > 0 && old_color == image[x][y - 1])
        searchNpaint(color, x, y - 1, m, n);
    if (x < m - 1 && old_color == image[x + 1][y])
        searchNpaint(color, x + 1, y, m, n);
    if (y < n - 1 && old_color == image[x][y + 1])
        searchNpaint(color, x, y + 1, m, n);
}

int main() {
    while (true) {
        char c, color;
        int m, n, x1, x2, y1, y2;
        string name;

        scanf(" %c", &c);

        switch (c) {
            case 'I':
                scanf(" %d %d", &m, &n);
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        image[i][j] = '0';
                break;
            case 'C':
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        image[i][j] = '0';
                break;
            case 'L':
                scanf(" %d %d %c", &x1, &y1, &color);
                x1--; y1--;
                image[x1][y1] = color;
                break;
            case 'V':
                scanf(" %d %d %d %c", &x1, &y1, &y2, &color);
                x1--; y1--; y2--;
                for (int i = y1; i <= y2; i++)
                    image[x1][i] = color;
                break;
            case 'H':
                scanf(" %d %d %d %c", &x1, &x2, &y1, &color);
                x1--; x2--; y1--;
                for (int i = x1; i <= x2; i++)
                    image[i][y1] = color;
                break;
            case 'K':
                scanf(" %d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
                x1--; x2--; y1--; y2--;
                for (int i = x1; i <= x2; i++)
                    for (int j = y1; j <= y2; j++)
                        image[i][j] = color;
                break;
            case 'F':
                scanf(" %d %d %c", &y1, &x1, &color);
                x1--; y1--;
                searchNpaint('1', x1, y1, m, n);
                searchNpaint(color, x1, y1, m, n);
                break;
            case 'S':
                scanf(" ");
                getline(cin, name);
                printf("%s\n", name.c_str());
                for (int j = 0; j < n; j++) {
                    for (int i = 0; i < m; i++)
                        printf("%c", image[i][j]);
                    printf("\n");
                }
                break;
            case 'X':
                return 0;
            default:
                string trash;
                getline(cin, trash);
        }
    }
    return 0;
}
