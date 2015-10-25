#include <iostream>

using namespace std;

int pai[111];

void compress(int x) 
{
    int a = x;
    int b;

    while (pai[a] != a)
        a = pai[a];

    while (pai[x] != a) 
    {
        b = pai[x];
        pai[x] = a;
        x = b;
    }
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

            if (pai[x] == pai[y])
                continue;

            compress(x);
            compress(y);
            pai[pai[x]] = pai[y];
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
