#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    for(int i=2; i*i<=n; ++i) if(n%i==0) return 0;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (prime(n)) {printf("1\n%d\n", n); return 0;}
    n-=3;
    for(int i=3; i<n; i+=2) if (prime(i) && prime(n-i)) {printf("3\n3 %d %d\n", i, n-i); break;}
}
