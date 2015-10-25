#include <iostream>

using namespace std;

int main() {

    int n, dif, cache;
    int test = 1;

    while(cin >> n && n != 0) {
        cout << "Teste " << test++ << endl;
        dif = 0;

        for(int i = 0; i < n; i++) {
            cin >> cache;
            dif += cache;
            cin >> cache;
            dif -= cache;
        }

        if(dif > 0)
            cout << "Aldo" << endl << endl;
        else
            cout << "Beto" << endl << endl;
    }


    return 0;
}
