#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int x, h, y, i;
    int c=0;
    bool last_cut = true;

    scanf("%d %d", &y, &i); c++;
    for(int j=0; j<n-1; j++) {
        scanf("%d %d", &x, &h);
        if (last_cut) {
            if (x - h > y) {y = x; c++;}
            else {last_cut = false; y = x; i = h;}
        } else {
            if (y + i < x){c++; y+=i;}
            if (x - h > y) {c++; last_cut=true;}
            y = x; i = h;
        }
    }

    if (!last_cut) c++;
    printf("%d\n", c);

    return 0;
}
