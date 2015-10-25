#include <bits/stdc++.h>

using namespace std;

long long int X[3005];
long long int Y[3005];
int MIN[3005];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n;i++) scanf(" %lld %lld", &X[i], &Y[i]);
        for (int i = 1; i <= n; i++) MIN[i] = 3000;
        for (int i=1; i<=n;i++){
            for (int j=1; j<=n;j++) {
                if (j==i) continue;
                int d = 0;
                int e = 0;
                int k;
                for (k =1; k <=n;k++) {
                    if (k==i) continue;
                    if (k==j) continue;
                    if( (X[i]-X[j])*(Y[k]-Y[j]) > (Y[i]-Y[j])*(X[k]-X[j])) d++;
                    if( (X[i]-X[j])*(Y[k]-Y[j]) < (Y[i]-Y[j])*(X[k]-X[j])) e++;
                }
                if (d < MIN[i]) MIN[i] = d;
                if (e < MIN[i]) MIN[i] = e;
            }
        }

        printf("Case #%d:\n", t);
        if (n==1)
            printf("1\n");
        else {
            for (int i = 1; i<=n; i++)
                printf("%d\n", MIN[i]);
        }
    }
    return 0;
}
