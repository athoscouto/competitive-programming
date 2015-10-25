#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adjl2;

void djk(int u) {
    priority_queue<int, vector<int> > fringe;
    vector<int> temp;
    fringe.push_back(u, temp);
    while(!fringe.empty())
}
int main() {
    int n, m, u, v, w;
    vector<pair<int, int > > adjl;
    adjl.resize(n);
    for(int i=0; i<m; i++) { scanf("%d %d %d", &u, &v, &w); adjl[u] = pair<int, int>(v, w);}
    scanf("%d", &u);


    return 0;
}
