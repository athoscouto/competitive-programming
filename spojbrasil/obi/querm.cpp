#include <iostream>

using namespace std;

int main() {
	int n, i, ticket;
	int j = 1;
	while(true) {

		//cout << "N: ";
		cin >> n;

		if(n == 0) break;

		for(i = 1; i <= n; i++) {
			cin >> ticket;
			if (ticket == i) {
				cout << "Teste " << j << endl << i << endl << endl;
				j++;
			}
		}
	}

	return 0;
}
