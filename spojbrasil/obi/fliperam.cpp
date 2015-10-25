#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n, m, cache;

	cin >> n >> m;

	vector<int> pont;
	vector<int>::iterator it;

	cin >> cache;
	pont.push_back(cache);

	for(int i = 0; i < n-1; i++) {
		cin >> cache;
		it = pont.begin();

		for(int j = 0; j <= i; j++) {
			if(cache <= pont[j]) {
				pont.insert(it + j, cache);
				break;
			}
			else if(i == j)
				pont.push_back(cache);
		}
	}

	for(int i = n - 1; i >= n - m; i--)
		cout << pont[i] << endl; 
	
	return 0;
}

	
