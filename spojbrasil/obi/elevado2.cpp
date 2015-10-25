#include <iostream>

using namespace std;

int main() {
	int n, c, cache;
	int current = 0;
	cin >> n >> c;

	for(int i = 0; i < n; i++) {
		cin >> cache;	
		current -= cache;
		cin >> cache;	
		current += cache;

		if(current > c) {
			cout << 'S' << endl;
			return 0;;
		}
	}
		cout << 'N' << endl;
	return 0;
}
