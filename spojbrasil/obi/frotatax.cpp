#include <iostream>
using namespace std;

int main() {
	float A, G, Ra, Rg;

	cin >> A >> G >> Ra >> Rg;

	if(A/Ra < G/Rg)
		cout << "A" << endl;
	else
		cout << "G" << endl;
	
	return 0;

}
