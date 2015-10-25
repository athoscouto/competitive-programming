#include <iostream>
using namespace std;


int main() {
	int n, l, c;
	int cq = 0;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> l >> c;

		if(l > c)
			cq += c;
	}

	cout << cq;
	
	return 0;
}
