#include <iostream>

using namespace std;


int main() {
	int n, m, cache, prod = 0;

	cin >> n >> m;

	int mat[n][m];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];

		
	for(int i = 0; i < n; i++) {
		cache = 0;
		for(int j = 0; j < m; j++)
			cache += mat[i][j];

		if(cache > prod)
			prod = cache;
	}

	for(int j = 0; j < m; j++) {
		cache = 0;
		for(int i = 0; i < n; i++)
			cache += mat[i][j];

		if(cache > prod)
			prod = cache;
	}

	cout << prod << endl;

	return 0;
}
