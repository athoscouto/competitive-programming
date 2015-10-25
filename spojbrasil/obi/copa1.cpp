#include <bits/stdc++.h>

using namespace std;

int main() {

    bool jogos[16];
    int x, y;
    for (int i = 1; i <= 16; i++) {
        cin >> x >> y;
        jogos[i] = x > y;
    }

    int cur = 15;
    for (int i = 0; i < 3; i++) {
        if (jogos[cur])
            cur =  2*cur - 17;
        else
            cur = 2*cur - 16;
    }

    if (jogos[cur])
        cur = 2*cur - 1;
    else
        cur = 2*cur;

    cout << (char)('A' - 1 + cur) << endl;

    return 0;
}
