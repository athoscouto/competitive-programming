#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF) printf("%c\n", a != b and a != c ? 'A' : b != a and b != c ? 'B' : b != c and a != c ? 'C' : '*');
    return 0;
}
