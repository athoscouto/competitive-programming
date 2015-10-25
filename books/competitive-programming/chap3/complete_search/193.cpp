#include <bits/stdc++.h>

using namespace std;

int clr[1001], mclr[1001];
vector<int> adj[1001];
int m, n, k, cntr, mcntr;

void cs(int node) {
    if (node == n) {
        if (cntr > mcntr) {
            mcntr = cntr;
            for(int i=0; i<n; ++i) mclr[i]=clr[i];
        }
        return;
    }
    if (clr[node] == 0) {
        clr[node] = 1; cntr++;
        for(int i=0; i<adj[node].size(); ++i) clr[adj[node][i]]--;
        cs(node+1);

        clr[node] = 0; cntr--;
        for(int i=0; i<adj[node].size(); ++i) clr[adj[node][i]]++;
        cs(node+1);
    }
    else cs(node+1);
}

int main() {
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &n, &k);
        cntr = 0; mcntr = 0;
        for(int i=0; i<n; ++i) {adj[i].clear(); clr[i] = 0;}
        for(int i=0; i<k; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        cs(0);
        printf("%d\n", mcntr);
        int j=0;
        for(int i=0; i<n; ++i) if (mclr[i] == 1) {printf("%d", i+1); if(j!=mcntr-1) printf(" "); j++;}
        printf("\n");
    }
}
