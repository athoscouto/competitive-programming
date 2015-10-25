#include <bits/stdc++.h>

using namespace std;

int g[500][500];
int M;
int ma[500];

void max_row(int i, int m) {
    int cc = 0; ma[i] = 0;
    for(int j=0; j<m; j++)
        if (g[i][j] == 1) {cc++; ma[i] = max(ma[i], cc);}
        else cc = 0;
}
void max_(int n) {
    M = 0;
    for(int i=0; i<n; i++)
        M = max(M, ma[i]);
}


int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &g[i][j]);

    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {printf("%d ", g[i][j]);}
        printf("\n");
    }
    */
    for(int i=0; i<n; i++) max_row(i, m);

    for(int k=0; k<q; k++) {
        int i, j;
        scanf("%d %d", &i, &j); i--; j--;
        g[i][j] = (g[i][j] + 1)%2;
        max_row(i, m);
        max_(n);

        printf("%d\n", M);
    }


    return 0;
}
