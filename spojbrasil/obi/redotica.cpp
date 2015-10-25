// Créditos: Geraldo Avelino
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int pai[111];
vector<piii> v;

int FindSet(int x) {
    return (pai[x]==x) ? x : pai[x]=FindSet(pai[x]);
}

void Union(int x, int y) {
    int X=x, Y=y;
    x=FindSet(x);
    y=FindSet(y);
    if(x==y) return;
    if(X>Y) swap(X, Y);
    printf("%d %d\n", X, Y);
    pai[x]=y;
}

int main()
{
    int n, m, t=1;

    while(cin >> n >> m && n)
    {
        v.clear();
        for(int i=1; i<=n; i++) pai[i]=i;

        for (int i = 0; i < m; i++)
        {
             int a, b, c;
             scanf("%d %d %d", &a, &b, &c);
             v.push_back(piii(c, pii(a, b)));
             //v.push_back(make_pair(c, make_pair(a, b)));
        }

        sort(v.begin(), v.end());

        printf("Teste %d\n", t++);

        for(int i=0; i<m; i++) 
        {
            int a, b;
            a=v[i].ss.ff;
            b=v[i].ss.ss;
            Union(a, b);
        }

        printf("\n");
    }
}
