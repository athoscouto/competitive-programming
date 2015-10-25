#include <bits/stdc++.h>

using namespace std;

int ca[26], cb[26], cc[26];
int cd[26];

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int al=a.size(), bl = b.size(), cl=c.size();

    for(int i=0; i<26; ++i) ca[i] = cb[i] = cc[i] = 0;
    for(int i=0; i<al; ++i) ca[a[i] - 'a']++;
    for(int i=0; i<bl; ++i) cb[b[i] - 'a']++;
    for(int i=0; i<cl; ++i) cc[c[i] - 'a']++;

    int maxb = cb[0] != 0 ? ca[0] / cb[0] : 1000000;
    for(int i=1; i<26; ++i) maxb = min(maxb, cb[i] != 0 ? ca[i] / cb[i] : 1000000);

    int k = maxb;
    int l=maxb, m=0;
    for(int i=maxb; i>=0; --i) {
        for(int j=0; j<26; ++j) cd[j] = ca[j] - i*cb[j];
        int maxc = cc[0] != 0 ? cd[0] / cc[0] : 1000000;
        for(int j=1; j<26; ++j) maxc = min(maxc, cc[j] != 0 ? cd[j] / cc[j] : 1000000);
        if (i + maxc > k) {
            k = i + maxc;
            l = i;
            m = maxc;
        }
    }
    for(int j=0; j<26; ++j) cd[j] = ca[j] - l*cb[j] - m*cc[j];

    for(int i=0; i<l; ++i) cout << b;
    for(int i=0; i<m; ++i) cout << c;
    for(int i=0; i<26; ++i) for(int j=0; j<cd[i]; ++j) cout << (char)('a'+i);
    cout << endl;

    return 0;
}
