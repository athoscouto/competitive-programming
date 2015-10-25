#include <iostream>
using namespace std;

int main() {
	
	int x1, x2, x3, y1, y2, y3, n;
	int test = 1;
	int counter;
	
	while(true) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
			break;

		counter = 0;
		cout << "Teste " << test++ << endl;
		cin >> n;
		
		for(int i = 0; i < n; i++) {
			cin >> x3 >> y3;

			if( (x1 <= x3 && x3 <= x2) && (y1 >= y3 && y3 >= y2) )
				counter++;
		}

		cout << counter << endl;
	}
		
	return 0;
}
