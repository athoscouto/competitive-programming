#include <iostream>
#include <map>

using namespace std;

int main() {

    int n, cache, cur, imax;
    int max = 0;
    cin >> n;

    map<int, int> votos;

    for (int i = 0; i < n; i++) {
        cin >> cache;

        if (votos.find(cache) != votos.end())
            cur = ++votos[cache];
        else
            votos[cache] = 1;

        if (max < cur) {
            max = cur;
            imax = cache;
        }
    }

    cout << imax << endl;

    return 0;
}	
