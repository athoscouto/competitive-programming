#include <bits/stdc++.h>
using namespace std;

int main() {
    int test = 1;
    int pro, con, saldo_partida, max, ini, fin, n;

    while(cin >> n && n) {
        cout << "Teste " << test++ << endl;
        max = -51;

        ini = 1;
        fin = 0;
        int saldo=0, inimax=0, finmax=0;

        for(int i=1; i<=n; i++) {
            cin >> pro >> con;

            saldo += pro - con;
            if (saldo >= 0) {
                fin = i;

                if (saldo > max || (saldo == max && (fin - ini) > (finmax - inimax))) {
                    max = saldo;
                    inimax = ini;
                    finmax = fin;
                }
            } else {
                ini = i + 1;
                saldo = 0;
            }
        }

        if (finmax == 0)
            cout << "nenhum\n\n";
        else
            cout << inimax << " " << finmax << endl << endl;
    }
    return 0;
}
