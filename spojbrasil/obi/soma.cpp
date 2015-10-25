#include <iostream>
using namespace std;

int main() {
	int cache = 0, sum = 0, n = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> cache;
		sum += cache;
	}
	cout << sum;
	return 0;
}
