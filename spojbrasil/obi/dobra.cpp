#include <iostream>

using namespace std;

int main () {
	int n, test = 1;

	while(true) {
		cin >> n;
		if (n == -1) break;
		cout << "Teste " << test++ << endl;

		cout << ((1 << (2*n)) + (1 << (n + 1)) + 1 ) << endl << endl;
	}
	return 0;
}
