#include <iostream>

using namespace std;

int main() {

	int n, num, sum;
	int test = 1;
	char o;


	while(true) {
		cin >> n;
		if(n == 0) break;

		cout << "Teste " << test++ << endl;

		cin >> sum;
		for(int i = 0; i < n - 1; i++) {
			cin >> o;
			cin >> num;

			if(o == '+')
				sum += num;
			else
				sum -= num;
		}
		cout << sum << endl << endl;
	
	}


	return 0;
}
