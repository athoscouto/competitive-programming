#include <iostream>

using namespace std;


int main() {

	int n;

	cin >> n;

	if (n == 0) 
		cout << 'E';
	else if (n <= 35)
		cout << 'D';
	else if (n <= 60)
		cout << 'C';
	else if (n <= 85)
		cout << 'B';
	else if (n <= 100)
		cout << 'A';

	return 0;
}
