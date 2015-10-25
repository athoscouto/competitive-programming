#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int test = 1;

	while(true) {
		cin >> n;
		if(n == 0) break;
		cout << "Teste " << test++ << endl;
		cout << (2 << n - 1) - 1 << endl << endl;
	}

	return 0;
}
