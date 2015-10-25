#include <bits/stdc++.h>

using namespace std;

int main() {
    char l;
    vector<int> dict[2256];
    for(int i=0; scanf("%c", &l) && l !='\n'; ++i) dict[l].push_back(i);
    // for(int i='a'; i<='z'; ++i) {printf("%c: ", i); for(int j=0; j<dict[i].size(); ++j) printf("%d ", dict[i][j]); printf("\n");}
    // for(int i='A'; i<='Z'; ++i) {printf("%c: ", i); for(int j=0; j<dict[i].size(); ++j) printf("%d ", dict[i][j]); printf("\n");}

    int n;
    scanf("%d ", &n);
    while(n--) {
        char query[1000];
        int size, index=0, start, end;
        bool found;
        for(size=0; scanf("%c", &query[size]) && query[size] != '\n'; ++size);
        // for(int i=0; i<size; ++i) printf("%c", query[i]); printf("\n");
        for(int i=0; i<size; ++i) {
            found = false;
            vector<int>::iterator it = lower_bound(dict[query[i]].begin(), dict[query[i]].end(), index);
            if (it != dict[query[i]].end() && index <= *it) {
                index = (*it)+1;
                found = true;
                if(i==0) start = *it;
                if(i==size-1) end = *it;
                // printf("found1 %c, pos %d\n", query[i], index);
            }
            else break;
        }
        if (found) printf("Matched %d %d\n", start, end);
        else printf("Not matched\n");
    }
    return 0;
}
