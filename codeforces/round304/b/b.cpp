#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s=0, t;
    vector<int> c;
    scanf("%d", &n);
    for(int i=0; i<n;i++) {scanf("%d", &t); c.push_back(t);}
    sort(c.begin(), c.end());
    t=c[0];
    for(int i=1; i<c.size(); i++)
        if (c[i] <= t) {s+=t-c[i]+1; t++;}
        else {t=c[i];}
    printf("%d\n", s);
    return 0;
}
