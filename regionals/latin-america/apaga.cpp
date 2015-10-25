#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d, num;

    while(true) {
        cin >> n >> d;

        if (n == 0 && d == 0)
            break;

        int m = n - d, num_apagados = 0;
        int dig[n], res[m];
        char buffer;

        vector<bool> apagados;
        apagados.resize(n);

        for (int i = 0; i < n; i++) {

            cin >> buffer;
            dig[i] = buffer - '0';

            // Se ja apagou tudo, so acaba de receber os numeros
            if (num_apagados == d)
                continue;

            // Compara o numero recebido com os anteriores
            // para ver se deve apagar algum anterior
            for (int j = i - 1; j >= 0; j--) {
                if (apagados[j])
                    continue;

                if (dig[j] < dig[i]) {
                    apagados[j] = true;
                    num_apagados++;
                }
                // Se ja apagou o suficiente, nao compara mais
                if (num_apagados == d)
                    break;
            }
        }

        // Imprime apenas a quantidade total menos a que deve ser apagada
        int imprimidos = 0;
        for (int i = 0; i < n; i++) {
            if (apagados[i])
                continue;
            cout << dig[i];

            if (++imprimidos == m)
                break;
        }

        cout << endl;


    }
    return 0;
}
