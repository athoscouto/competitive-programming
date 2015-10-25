#include <bits/stdc++.h>

using namespace std;

int M[100001];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int b, n;
        scanf(" %d %d", &b, &n);
        int max = 0;
        int min = 100001;
        for (int i = 0; i < b; i++) {
            scanf(" %d", &M[i]);
            if (M[i] < min) min = M[i];
            if (M[i] > max) max = M[i];
        }
        long long int s = (n -1)*min/b;
        long long int S = (n)*max/b;

        long long int mean;
        int N;
        while(true) {

            mean = (s + S) / 2;

            N = b;
            for (int i =0; i<b;i++) N += mean / M[i];

            if (mean == (s + S) / 2) break;

            if (N == n)break;
            if (N > n) S = mean;
            if (N < n) s = mean;
        }

        while (n>N) {
            mean++;
            N = b;
            for (int i =0; i<b;i++) N += mean / M[i];
        }
        while (n<=N) {
            mean--;
            N = b;
            for (int i =0; i<b;i++) N += mean / M[i];
        }
        mean++;

        int i;
        int lasti = 1;
        for(i =0; i<b; i++) {
            if (mean % M[i] ==0) {
                N++;
                if (N == n) {
                    N--;
                    break;
                } 
            }
        }

        printf("Case #%d: %d\n", t, i+ 1);

    }
    return 0;
}
