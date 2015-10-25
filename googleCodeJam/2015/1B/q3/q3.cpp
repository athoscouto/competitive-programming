#include <bits/stdc++.h>

using namespace std;

long int M[500000];
long int m[500000];
int main() {
    int T;
    scanf("%d", &T);

    for(int t=1;t<=T;t++) {
        long int N, P, H, M_, c=0;
        scanf("%ld", &N);
        for(int i=0;i<N;i++){
            scanf("%ld %ld %ld", &P, &H, &M_);
            for(int j=0; j<H; j++) { M[c] = 360*(M_ + j); m[c++] = (360-P)*(M_+j);}
        }
        long int ts;
        long int e =50232300029;
        for (int i=0; i<c;i++) {
            ts = m[i]; long int f = 0;
            for (int j=0; j<c;j++) { if(m[j] < ts) f += (ts - m[j])/M[j]; else if(m[j] > ts) f += (m[j] - ts)/M[j] + 1; }
            e = min(e, f);
        }
        printf("Case #%d: %ld\n", t, e);
    }
    return 0;
}
