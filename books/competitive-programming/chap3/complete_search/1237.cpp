#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, D, L[100000], H[100000], Q, P[100000+1];
    char M[100000][21];

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &D);
        for(int i=0; i<D; i++) scanf("%s %d %d", M[i], &L[i], &H[i]);
        scanf("%d", &Q);
        for(int i=0; i<Q; i++) scanf("%d", &P[i]);

        for(int i=0; i<Q; i++) {
            int found = -1;
            for(int j=0; j<D; j++) {
                if (L[j] <= P[i] && P[i] <= H[j]) {
                    if (found >= 0) {found = -1; break;}
                    else found = j;
                }
            }
            if (found >= 0) printf("%s\n", M[found]);
            else printf("UNDETERMINED\n");
        }
        if (T>0) printf("\n");
    }
    return 0;
}
