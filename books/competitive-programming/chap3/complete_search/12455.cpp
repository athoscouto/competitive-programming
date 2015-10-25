#include <bits/stdc++.h>

using namespace std;
int t, n, p, l[30];
bool found;
int m;

void cs(int s) {
    if (s==p) {
        int sum =0;
        for(int i=0; i<p; ++i) if(1<<i & m) sum+=l[i];
        if (sum == n) found = 1;
        return;
    }
    cs(s+1);
    m += (1<<s);
    cs(s+1);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        m = found = 0;
        scanf("%d %d", &n, &p);
        for(int i=0; i<p; ++i) scanf("%d", &l[i]);
        cs(0);
        if (found) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
