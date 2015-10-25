#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> a;
	vector<int>::iterator b;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	b = a.begin() + 2;
	
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	a.insert(b, 10);
	
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;

}
