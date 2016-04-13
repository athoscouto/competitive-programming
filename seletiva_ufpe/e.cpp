#include <bits/stdc++.h>
using namespace std;

const int N = 101, M=30;
int t, T, ma[M], mi[M], to[M];
char s[N];
long long r;

long long c(int n, int m) {
    long long r=1;
    for(int i=0; i<m; ++i) r *= (n-i), r /= (i+1);
    return r;
}

int main() {
    scanf("%d", &T);

    while(t++ < T) {
        r = 1;
        for(int i=0; i<M; ++i) ma[i] = mi[i] = to[i] = 0;
        scanf(" %s", s);

        for(int i=0; s[i]; ++i) if (s[i] != '_') {
            if (s[i] > 'Z') mi[s[i]-'a']++, to[s[i]-'a']++;
            else ma[s[i]-'A']++, to[s[i]-'A']++;
        }

        for(int i=0; i<M; ++i) r *= c(to[i], min(ma[i], mi[i]));
        printf("Caso #%d: %lld\n", t, r-1);
    }


    return 0;
}
