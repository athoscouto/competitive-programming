#include <iostream>
#include <string>

using namespace std;

int main() {

	int n, num1, num2;
	int counter = 1;
	string nome1, nome2;

	while(cin >> n && n != 0) {
		cout << "Teste " << counter++ << endl;
		cin >> nome1 >> nome2;

		for(int i = 0; i < n; i++) {
			cin >> num1 >> num2;
			if((num1 + num2) % 2) 
				cout << nome2 << endl;
			else
				cout << nome1 << endl;

		}
		cout << endl;
	}
	return 0;
}
