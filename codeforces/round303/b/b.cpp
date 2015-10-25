#include <bits/stdc++.h>

using namespace std;
int main() {
    char a[111111], b[111111];
    char temp;

    int n; a[0] = 'c';
    int j = 0;
    do{ scanf("%c", &a[n]); n++;} while(a[n-1] != '\n'); n--;
    for(int i=0; i<n; i++) {
        scanf("%c", &temp);
        b[i] = j % 2 ? temp : a[i];
        if (a[i] != temp) j++;
    }

    if (j%2 == 1) printf("impossible\n");
    else for(int i=0; i<n; i++) printf("%c", b[i]);
    printf("\n");

    return 0;
}
