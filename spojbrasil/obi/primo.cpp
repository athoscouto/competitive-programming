#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void next_prime(vector<int>& primes) {
	// Recebe um vetor de tamanho n, com os n primeiros primos ordenados
	// e modifica esse vetor adicionando o primo n+1 ao final do vetor

	int next_prime = primes.back();
	int psqrt;
	bool is_prime;

	while(true) {
		next_prime += 2;
		psqrt = sqrt(next_prime);
		is_prime = true;

		// Realiza o crivo. Ou seja, testa se todos os primos até
		// a raíz do número dividem o número.
		for(int i = 0; primes[i] <= psqrt; i++)
			if(next_prime % primes[i] == 0) {
				is_prime = false;	
				break;
			}

		if(is_prime)  {
			primes.push_back(next_prime);
			break;
		}
	}
}



int main() {
	
	vector<int> primes;
	int n, nsqrt;
	bool is_prime = true;

	primes.push_back(2);
	primes.push_back(3);

	cin >> n;
	nsqrt = sqrt(n);
	
	while(nsqrt > primes.back())
		next_prime(primes);

	for(int i = 0; i < primes.size(); i++) {
		if(n % primes[i] == 0) {
			is_prime = false;
			cout << "nao" << endl;
			break;
		}
	}

	if(is_prime) cout << "sim" << endl;

	return 0;
}
