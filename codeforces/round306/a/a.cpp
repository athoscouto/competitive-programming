#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int ab, ba;
    bool AB=false, BA=false;
    int t = s.size();

    for(int i=0; i < t-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            if (!AB) {ab = i; AB = true;}
            if (BA && ba + 1 != i) {printf("YES\n"); return 0;}
        } if (s[i] == 'B' && s[i+1] == 'A') {
            if (!BA) {ba = i; BA = true;}
            if (AB && ab + 1 != i) {printf("YES\n"); return 0;}
        }
    }
    printf("NO\n");
    return 0;
}
