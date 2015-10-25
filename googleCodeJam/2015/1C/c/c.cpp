#include <bits/stdc++.h>
using namespace std;
long int d[100];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int  C, D, V;
        scanf("%d %d %d", &C, &D, &V);
        for(int i=0; i<D; i++) scanf("%ld", &d[i]);
        int i=0, j=0;
        long int range=0;
        while(range < V)
            if(range >= d[j]-1 && j < D) {range += C*d[j]; j++;}
            else {range += C*(range+1); i++;}
        printf("Case #%d: %d\n", t, i);
    }
    return 0;
}
