#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int a[10];
    int max = 0;
    for (int i = 0; i < 10;i++) a[i]=0;

    scanf("%d", &n);

    int base = 1;
    while (n > 0) {
        if (n % 10 > max) max = n % 10;
        for(int i =0; i < n % 10; i++)
            a[i] += base;
        base *= 10;
        n /= 10;
    }

    printf("%d\n", max);
    for(int i =0; i< max; i++)
        printf("%d ", a[i]);


    return 0;
}
