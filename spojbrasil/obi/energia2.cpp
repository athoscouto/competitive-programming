// Credits: Geraldo Avelino
#include <iostream>

using namespace std;

int pai[111];

int FindSet(int x) {
    return (pai[x]==x) ? x : pai[x]=FindSet(pai[x]);
}

void Union(int x, int y) {
    x=FindSet(x);
    y=FindSet(y);
    if(x==y) return;
    pai[x]=y;
}


int main() {

    int e, l, x, y;
    int test = 1;

    while (cin >> e >> l && e && l) {

        for (int i = 1; i <= e; i++) pai[i] = i;

        int a, b, c;

        for (int i = 0; i < l; i++)
        {
            cin >> x >> y;
            Union(x, y);
        }

        int cnt = 0;
        for (int i = 1; i <= e; i++)
            if (pai[i] == i) 
                if (++cnt > 1) 
                    break;

        cout << "Teste " << test++ << endl;
        if (cnt == 1)
            cout << "normal" << endl << endl;
        else if (cnt > 1) 
            cout << "falha" << endl << endl;
    }

    return 0;
}
