#include <bits/stdc++.h>
using namespace std;

int cst[1<<21], p, b, m, M[20], c=1, aux, aux2, B, max_sum, maxB, t;

int slv() {
    int sum=0;
    for(int i=0; i<p; ++i) if ((1<<i) & B) sum += cst[1<<i];
    for(int i=0; i<m; ++i) if (M[i] & B) {
        int k = (M[i] & B);
        while(k-=(k&(-k))) sum -= cst[M[i]];
    }
    if (sum > max_sum) {max_sum = sum; maxB = B;}
}

void cs(int s, int k) {
    if (k == 0) {slv(); return;}
    for(int i=s; i<p-k+1; ++i) {
        B += (1 << i);
        cs(i+1, k-1);
        B -= (1 << i);
    }
}

int main() {
    while(scanf("%d %d", &p, &b) && p && b) {
        B = 0; max_sum = 0; memset(cst, 0, sizeof(cst));
        for(int i=0; i<p; ++i) {scanf("%d", &aux); cst[1<<i] = aux;}
        scanf("%d", &m);
        for(int i=0; i<m; ++i) {
            aux = 0;
            scanf("%d", &t);
            for(int j=0; j<t; ++j) {scanf("%d", &aux2); aux += (1 << (aux2-1));}
            scanf("%d", &aux2);
            cst[aux] = aux2;
            M[i] = aux;
        }
        cs(0, b);

        printf("Case Number  %d\n", c++);
        printf("Number of costumers: %d\n", max_sum);
        printf("Locations recommended:");
        for(int i=0; i<p; ++i) if(1<<i & maxB) printf(" %d", i+1);
        printf("\n\n");
    }
    return 0;
}
