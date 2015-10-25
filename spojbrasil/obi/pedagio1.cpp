#include <iostream>

using namespace std;

int main() {
	int L, D, K, P;

	cin >> L >> D >> K >> P;

	cout << (L*K + (L/D)*P) << endl;
	return 0;
}
