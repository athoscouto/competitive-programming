#include <iostream>

using namespace std;


int main() {

	int d, a, l, p;

	cin >> d >> a >> l >> p;

	if(d <= a && d <= l && d <= p)
		cout << "S" << endl;

	else
		cout << "N" << endl;

	return 0;
}
