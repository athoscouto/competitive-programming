#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    vector<int> a, b;
    a.resize(10000);
    b.resize(10000);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<N; ++i) scanf("%d", &a[i]);

        for(int i=1; i<N; ++i) {
            b[i-1] = 0;
            for(int j=0; j<i; ++j) if (a[j] <= a[i]) b[i-1]++;
        }

        int sum=0;
        for(int i=0; i<N-1; ++i) sum += b[i];
        printf("%d\n",sum);
    }


    return 0;
}
