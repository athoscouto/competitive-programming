// Acha o primo usando o crivo
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool crivo(int n) {
    int nsqrt = floor(sqrt(n));
    bool primes[nsqrt + 1] = {};

    for(int i = 2; i < nsqrt; i++) {
        if(primes[i]) continue;

        for(int j = 2; j*i < nsqrt; j++)
            primes[j*i] = true;
    }

    for(int i = 2; i <= nsqrt; i++) {
        if(primes[i]) continue;

        if(n % i == 0) return false;
    }

    return true;
}

int main() {
    int n;

    cin >> n;

    if(crivo(n)) cout << "sim" << endl;
    else cout << "nao" << endl;

    return 0;
}
