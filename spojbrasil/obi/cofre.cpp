#include <iostream>

using namespace std;

int main() {
	int n, diff, cache;
	int test = 1;

	while((cin >> n) && n) {
		cout << "Teste " << test++ << endl;
		diff = 0;

		for(int i = 0; i < n; i++) {
			cin >> cache; 
			diff += cache;
			cin >> cache;
			diff -= cache;
			cout << diff << endl;
		}

		cout << endl;

	}

	return 0;
}
