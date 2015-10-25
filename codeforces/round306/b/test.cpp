#include <bits/stdc++.h>

using namespace std;

int main() {
    int num = 15;
    for(int i=0; i < 4; i++)
        printf("%d %d %d\n", num & 1<<i, num, 1<<i);
    return 0;
}
