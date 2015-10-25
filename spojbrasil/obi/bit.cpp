#include <iostream>
#include <string>
using namespace std;

int main() {
	int V, C, d, c, u;
	for(int i = 1; (cin >> V) && (V != 0); i++) {
		
		C = V/50;
		V %= 50;
		d = V/10;
		V %= 10;
		c = V/5;
		V %= 5;
		u = V;

		cout << "Teste " << i << endl;
		cout << C << ' ' << d << ' ' << c << ' ' << u << endl;
	}
	return 0;
}
