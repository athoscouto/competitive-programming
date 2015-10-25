#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int max, a, b;
    char opera;

    cin >> max >> a >> opera >> b;

    if (opera == '+') {
        if (a + b > max)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    } else {
        if (a * b > max)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    }

    return 0;
}
