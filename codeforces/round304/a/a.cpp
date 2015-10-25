#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", max(a*(1+c)*c/2 - b, 0));
    return 0;
}
