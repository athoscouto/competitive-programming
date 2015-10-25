#include <bits/stdc++.h>

using namespace std;

struct ret {
    int vs, vi, hs, hi;
} inter;

void intersection(struct ret a) {
    inter.vs = min (a.vs, inter.vs);
    inter.vi = max (a.vi, inter.vi);
    inter.hs = min (a.hs, inter.hs);
    inter.hi = max (a.hi, inter.hi);
}

bool valid() {
    return (inter.vs > inter.vi) && (inter.hs > inter.hi);
}

int main () {
    int n;
    int t = 1;
    while (cin >> n && n) {
        struct ret rets[n];
        for (int i = 0; i < n; i++)
            cin >> rets[i].hi >> rets[i].vs >> rets[i].hs >> rets[i].vi;

        inter = rets[0];
        for (int i = 1; i < n; i++)
            intersection(rets[i]);

        cout << "Teste " << t++ << endl;
        if (valid())
            cout << inter.hi << " " << inter.vs << " " << inter.hs << " " << inter.vi << endl << endl;
        else
            cout << "nenhum" << endl << endl;
    }
    return 0;
}
