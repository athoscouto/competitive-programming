#include <iostream>
using namespace std;
const int MAX_ALUNOS = 1000;
int main()
{
	int i, n;
	int turma=1;
	struct
	{
		int codigo, media;
	} alunos[MAX_ALUNOS];
	// le numero de alunos da primeira turma
	cin >> n;
	while (n > 0)
	{
		// le dados dos alunos
		for (i = 0; i < n; i++)
			cin >> alunos[i].codigo >> alunos[i].media;
		// procura aluno de maior media
		int valor_melhor = alunos[0].media;
		for (i = 1; i < n; i++)
			if (alunos[i].media > valor_melhor)
				valor_melhor = alunos[i].media;
		// escreve resposta
		cout << "Turma " << turma++ << "\n";
		for (i = 0; i < n; i++)
			if (alunos[i].media == valor_melhor)
				cout << alunos[i].codigo << " ";

		cout << "\n\n";
		// le numero de alunos da proxima turma
		cin >> n;
	}
	return 0;
}
