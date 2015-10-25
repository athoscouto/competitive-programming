#include <bits/stdc++.h>

using namespace std;

long long po(int i) {
    long long ans=1;
    while(i>0) {ans*=10; --i;}
    return ans;
}

int main() {
    long long n, m=10, i;
    long long sum = 0;
    scanf("%lld", &n);
    for(i=1; m<=n; ++i) {
        sum += 9*po(i-1)*i;
        m*=10;
    }
    m=m/10-1;
    sum += (n - m)*i;
    printf("%lld\n", sum);
    return 0;
}
