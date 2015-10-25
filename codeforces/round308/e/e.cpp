#include <bits/stdc++.h>

using namespace std;

string s;

long long operate(int l, int r) {
    long long sum=0;
    for(int x=l+1; x<r; x+=2)
            if (s[x+1] == '+' || x+1>=r) sum += s[x]-'0';
            else {
                int prod=s[x]-'0';
                while(x+1<r && s[x+1] == '*') {prod *= s[x+2]-'0'; x+=2;}
                sum+=prod;
            }
    return sum;
}

int main() {

    getline(cin, s);
    int mpos[17], j=1, ssize=s.size();
    for(int i=1; i<ssize; i+=2) if (s[i]=='*') mpos[j++] = i;
    mpos[0] = -1; mpos[j++] = ssize;

    long long sum = 0, sum1;
    for(int i=0; i<j; ++i) for(int k=i+1; k<j; ++k) {
        int l = mpos[i], r = mpos[k];
        sum1 = operate(l, r);
        while(r < ssize && s[r] == '*') {sum1 *= s[r+1] - '0'; r+=2;}
        while(l > 0 && s[l] == '*') {sum1 *= s[l-1] - '0'; l-=2;}
        sum1 += operate(-1, l) + operate(r, ssize);
        sum = max(sum, sum1);
    }

    printf("%lld\n", sum);
    return 0;
}
