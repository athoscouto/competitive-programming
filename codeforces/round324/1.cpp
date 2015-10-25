#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    if (n>1) {
        printf("1");
        int mod = (n-1) % 6;
        int base = 1;
        for(int i=1; i<n-1; ++i) printf("0");
        switch(t) {
            case(2):
                printf("0\n");
                break;
            case(3):
                printf("2\n");
                break;
            case(4):
                if (n == 2) printf("2");
                else printf("0\n");
                break;
            case(5):
                printf("0\n");
                break;
            case(6):
                printf("2\n");
                break;
            case(7):
                for(int i=0; i<mod; ++i) base *= 10;
                printf("%d\n", 7-base%7);
                break;
            case(8):
                if (n>3) printf("0\n");
                else if (n==3) printf("4\n");
                else printf("6\n");
                break;
            case(9):
                printf("8\n");
                break;
            case(10):
                printf("0\n");
        }
    }
    else {
        if (t!=10)
            printf("%d\n", t);
        else
            printf("-1\n");
    }
    return 0;
}
