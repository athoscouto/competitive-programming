#include <bits/stdc++.h>

using namespace std;
int main() {
    int temp, n, m[100][100], goods[100];
    int counter = 0;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        bool turned = false;
        for(int j=0; j<n; j++) {
            scanf("%d", &temp);
            if (temp == 1 || temp == 3) turned = true;
        }
        if (!turned) { goods[counter] = i; counter++; }
    }
    printf("%d\n", counter);
    for(int i=0; i<counter; i++) printf("%d ", goods[i]+1);
    printf("\n");
    return 0;
}
