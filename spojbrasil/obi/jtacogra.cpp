#include <iostream>

using namespace std;

int main() {

	int n, v, t, d = 0;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> t >> v;
		d += t*v;
	}

	cout << d << endl;
	return 0;
}
