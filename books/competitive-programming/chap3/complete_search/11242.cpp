#include <bits/stdc++.h>
using namespace std;

int main() {
    int f, r, F[11], R[11];
    float ra[101];
    while(scanf("%d", &f) && f!=0) {
        scanf("%d", &r);
        for(int i=0; i<f; ++i) scanf("%d", &F[i]);
        for(int i=0; i<r; ++i) scanf("%d", &R[i]);
        int k=0;
        for(int i=0; i<f; ++i)
            for(int j=0; j<r; ++j)
                ra[k++] = float(R[j])/F[i];
        sort(ra, ra+k);
        float max = 0;
        for(int i=0; i<k-1; ++i) max = (max > ra[i+1]/ra[i]) ? max : ra[i+1]/ra[i];
        printf("%.2f\n", max);
    }
    return 0;
}
