#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i=1; i<2000; ++i)
        for(int j=i; j<2000-i; ++j)
            for(int k=j; k<2000-i-j; ++k) {
                if(
                    i*j*k > 1000000 &&
                    1000000l*(i+j+k) % (i*j*k-1000000) == 0 &&
                    1000000l*(i+j+k) / (i*j*k-1000000) >= k &&
                    1000000l*(i+j+k) / (i*j*k-1000000) + k + j + i <= 2000)
                    printf("%.2f %.2f %.2f %.2f\n", i/100.0, j/100.0, k/100.0, 10000.0*(i+j+k) / (i*j*k-1000000));
            }
    return 0;
}
