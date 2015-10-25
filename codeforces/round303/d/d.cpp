#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, t;
    vector<int> m;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {scanf("%d", &t); m.push_back(t); }
    sort(m.begin(), m.end());

    int sum=0, c=0;
    for(int i=0; i<n; i++) if (m[i] >= sum) {sum += m[i]; c++;}

    printf("%d\n", c);
    return 0;
}
