#include <bits/stdc++.h>
using namespace std;

const int N = 8000;
int t, T, n, a[N], c[N], na, s;
queue<int> q;

int main() {
    scanf("%d", &T);
    while(t++ < T) {
        scanf("%d", &n);
        s = na = 0;
        memset(c, 0, sizeof c);
        for(int i=1; i<=n; ++i) scanf("%d", a+i), c[a[i]]++;
        for(int i=1; i<=n; ++i) {
            c[i] -= (a[i] == i);
            if (!c[i]) {
                if (a[i] != i) na++;
                q.push(i);
                s++;
            }
        }

        while(!q.empty()) {
            int i = q.front(); q.pop();
            c[a[i]]--;
            if (a[i] and !c[a[i]]) q.push(a[i]), s++;
        }

        printf("Caso #%d: %d %d\n", t, na, s);
    }
    return 0;
}
