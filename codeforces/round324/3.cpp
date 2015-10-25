#include <bits/stdc++.h>
using namespace std;

char diff(char a, char b) {
    if ('a' != a && 'a' != b) return 'a';
    if ('b' != a && 'b' != b) return 'b';
    if ('c' != a && 'c' != b) return 'c';
}

int main() {
    int n, t;
    int t1=0, t2=0;
    char s1[111111], s2[111111], d[111111];
    bool e[111111];
    scanf("%d %d", &n, &t);
    for(int i=0; i<n; ++i) scanf(" %c", &s1[i]);
    for(int i=0; i<n; ++i) {
        scanf(" %c", &s2[i]);
        if (s1[i] == s2[i]) {e[i] = 1;}
    }
    for(int i=0; i<n; ++i)
        if (e[i]) {d[i] = s1[i];}
        else {
            if (t1 <= t2) {d[i] = s2[i]; ++t1;}
            else {d[i] = s1[i]; ++t2;}
        }

    for(int i=0; t1<t && t2<t && i<n; ++i) if (e[i]) {
        d[i] = diff(s1[i], s2[i]);
        ++t1; ++t2;
    }

    for(int i=0; t1<t && i<n; ++i)
        if (s1[i] == d[i] && !e[i]) {
            d[i] = diff(s1[i], s2[i]);
            ++t1;
        }

    for(int i=0; t2<t && i<n; ++i)
        if (s2[i] == d[i] && !e[i]) {
            d[i] = diff(s1[i], s2[i]);
            ++t2;
        }

    if (t1 == t && t2 == t)
        for(int i=0; i<n; ++i) printf("%c", d[i]);
    else printf("-1");
    printf("\n");

    return 0;
}
