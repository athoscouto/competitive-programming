#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int m = s.size() / k;
    if (s.size() % k != 0) {cout << "NO\n"; return 0;}
    for(int i=0; i<k; i++) for(int j=0; j<m; j++)
        if(s[i*m+j] != s[(i+1)*m-j-1]) {cout << "NO\n"; return 0;}
    cout << "YES\n"; return 0;
}
