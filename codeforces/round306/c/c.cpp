#include <bits/stdc++.h>

using namespace std;

int main() {
    int s[100];
    int i=0;
    while(scanf("%1d", &s[i++]) != EOF);
    int n = i-1;

    for(int i=0; i<n; i++) {
        if (s[i] % 8 == 0) {printf("YES\n%d\n", s[i]); return 0;}
        for(int j=i+1; j<n; j++) {
            if ((10*s[i]+s[j]) % 8 == 0) {printf("YES\n%d%d\n", s[i], s[j]); return 0;}
            for(int k=j+1; k<n; k++) {
                if ((100*s[i]+10*s[j]+s[k]) % 8 == 0) {printf("YES\n%d%d%d\n", s[i], s[j], s[k]); return 0;}
            }
        }
    }

    printf("NO\n");
    return 0;
}
