#include <iostream>
using namespace std;

int main() {
	int n;
	int fat = 1;

	cin >> n;
	for(; n > 1; n--)
		fat *= n;

	cout << fat;
	return 0;
}
