#include <iostream>

using namespace std;

int main() {

	int N, preco;

	cin >> N;

	preco = 7;

	if (N > 10 && N <= 30)
		preco += N - 10;
	else if (N > 30 && N <= 100)
		preco += 2*N - 40;
	else if (N > 100)
		preco += 5*N - 340;

	cout << preco << endl;

	return 0;
}
