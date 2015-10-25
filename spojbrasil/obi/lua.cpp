#include <iostream>

using namespace std;

int main() {
	int test = 1;

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		cout << "Teste " << test++ << endl;

		int temp[n];

		for (int i = 0; i < n; i++)
			cin >> temp[i];

		int media = 0, max = -200*m, min = 200*m;

		/* MANEIRA INEFICIENTE
		for (int i = 0; i < n - m; i++) {
			media = 0;
			for (int j = 0; j < m; j++) 
				media += temp[i + j];
			if (media > max)
				max = media;
			if (media < min)
				min = media;
		}
		*/


		for (int i = 0; i < m; i++)
			media += temp[i];
		
		if (media > max) max = media;
		if (media < min) min = media;

		for (int i = 0; i < n - m; i++) {
			media -= temp[i];
			media += temp[i + m];

			if (media > max) max = media;
			if (media < min) min = media;
		}

		cout << min/m << " " << max/m << endl << endl;
	}
	return 0;
}
