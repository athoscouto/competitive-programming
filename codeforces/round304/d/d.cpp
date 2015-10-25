#include <bits/stdc++.h>
#define lmt 5000001
using namespace std;

long long p[lmt] = {0};

int main() {
    for(int i=2; i<lmt; i++) if (p[i]==0) {
        p[i]++;
        for(int j=2; j*i<lmt; j++) {
            int k = j*i;
            while (k%i==0) {k/=i; p[i*j]++;}
        }
    }
    for(int i=2; i<lmt; i++) p[i] += p[i-1];

    int T, a, b;
    scanf("%d", &T);
    for(int t=0; t<T;t++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", p[a] - p[b]);
    }
    return 0;
}
