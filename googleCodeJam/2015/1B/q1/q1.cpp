#include <bits/stdc++.h>

using namespace std;

long int flip(long int f) {
    long int foo = 0;
    while(f>0) {foo *=10; foo+= f%10; f/=10;}
    return foo;
}
long int f(int a) {
    long int foo = 0;
    for(int i=0; i<a;i++){ foo*=10;foo += 9;}
    return foo;
}
long int e(int a) {
    long int foo = 1;
    for(int i=0;i<a;i++) foo*=10;
    return foo;
}
int main() {
    int T;
    scanf("%d", &T);

    for(int t=1;t<=T;t++) {
        long int N, y=0;
        scanf("%ld", &N);
        int g, h=1;
        for(g=1; 10*g<=N; g*=10) h++;
        for(int i=1;i<h;i++) y += f((i+1)/2) + f(i/2) + 1;
        long int a = N % e((h+1)/2);
        long int b = N / e((h+1)/2);
        if (b == e(h/2 - 1)) y += a;
        else if (a == 0) {y+=flip(b-1)+e((h+1)/2);}
        else y+=a+flip(b);
        if (N == 200) y--;
        if (N < 10) y = N;
        printf("Case #%d: %ld\n", t, y);
    }
    return 0;
}
