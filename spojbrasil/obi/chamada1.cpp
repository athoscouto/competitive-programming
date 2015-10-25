#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, j;

    cin >> n >> j;

    vector<string> nomes;
    nomes.resize(n);

    for (int i = 0; i < n; i++)
        cin >> nomes[i];

    sort(nomes.begin(), nomes.end());

    cout << nomes[j-1] << endl;
    return 0;

}
