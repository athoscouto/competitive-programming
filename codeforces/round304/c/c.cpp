#include <bits/stdc++.h>

using namespace std;

queue<int> q1, q2;
void b() {
    int k1, k2;
    k1 = q1.front();
    q1.pop();
    k2 = q2.front();
    q2.pop();
    if (k1 > k2) { q1.push(k2); q1.push(k1);}
    else { q2.push(k1); q2.push(k2);}
}

int main() {
    int n, k, l, t;
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++) {scanf("%d", &t); q1.push(t);}
    scanf("%d", &l);
    for(int i=0; i<l; i++) {scanf("%d", &t); q2.push(t);}

    int i=0;
    while(true){
        if (q1.empty()) {printf("%d 2\n", i); return 0;}
        if (q2.empty()) {printf("%d 1\n", i);return 0;}
        if (i>100000) {printf("-1\n");return 0;}
        b(); i++;
    }

    return 0;
}
