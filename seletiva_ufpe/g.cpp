#include <bits/stdc++.h>
using namespace std;

const int N = 21, M = (1<<N);
int t, T, n, m, k, p, sm[M], nxt[M][26];
char s[N];

int dfs(int i) {
    sm[i] = 1;
    for(int j=0; j<26; ++j) if (nxt[i][j]) sm[i] += dfs(nxt[i][j]);
    return sm[i];
}

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        scanf(" %s%d", s, &m);
        n = strlen(s), k = 1;
        memset(nxt, 0, sizeof nxt);

        for(int i=1; i<(1<<n); ++i) {
            p = 1;
            for(int j=0; (1<<j)<=i; ++j) if (i&(1<<j)) {
                if (!nxt[p][s[j]-'a']) nxt[p][s[j]-'a'] = ++k;
                p = nxt[p][s[j]-'a'];
            }
        }

        dfs(1);

        printf("Caso #%d:\n", t);
        for(int i=0; i<m; ++i) {
            scanf(" %s", s);
            p = 1;
            for(int i=0; s[i]; ++i) p = nxt[p][s[i]-'a'];
            printf("%d\n", sm[p]);
        }
    }
    return 0;
}
