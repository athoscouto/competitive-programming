#include <iostream>

using namespace std;

int main() {

	int n, cache;

	cin >> n;

	cache = (n - 1986)/76 + 1;
	
	cout << 1986 + cache*76;

	return 0;
}

