#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, cache, test = 1;
	
	while(true) {
		cin >> n >> m;

		if(n == 0 && m == 0) break;

		cout << "Teste " << test++ << endl;

		int aero[n] = {};

		for(int i = 0; i < m; i++) {
			cin >> cache;
			aero[cache - 1]++;
			cin >> cache;
			aero[cache - 1]++;
		}

		cache = 0;
		vector<int> winner;

		for(int i = 0; i < n; i++) {
			if(aero[i] > cache) {
				cache = aero[i];
				winner.clear();
				winner.push_back(i+1);
			}
			else if(aero[i] == cache) 
				winner.push_back(i+1);
		}

		for(int i = 0; i < winner.size(); i++)
			cout << winner[i] << " ";
		cout << endl << endl;
	}

	return 0;
}
