#include <iostream>

using namespace std;

void quick_sort(int vetor[], int inicio_vetor,int fim_vetor)
{
	int i, j, pivo, aux;
	i = inicio_vetor;
	j = fim_vetor;
	pivo = vetor[(inicio_vetor + fim_vetor ) / 2];

	while( i < j ) 
	{
		while (vetor[i] < pivo )
		{
			i = i+1;			
		}
		while (vetor[j] > pivo)
		{
			j = j-1;
		}
		if (i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor [j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if ( j > inicio_vetor)
	{
		quick_sort(vetor,inicio_vetor, j);
	}
	if ( i < fim_vetor)
	{
		quick_sort(vetor, i, fim_vetor);
	}
}

int main (int argc, char** argv){

	srand(time(NULL));

	int n, tam, faixa;	
	char opcao;
	

	cout << "digite o tamanho do vetor : " << endl;
	cin >> tam;
	int elementos[tam];
	cout << "Digite a faixa de numeros aleatorios a ser colocados no vetor" << endl;
	cin >> faixa;

	for(int i{0} ; i < tam; i++){
		elementos[i] = rand() % faixa;
		cout << elementos[i] << " ";
	}
	cout << endl << "Deseja ordenar o vetor com o algoritmo MERGE_SORT ?  [S/N]" << endl;
	cin >> opcao;

	opcao = toupper(opcao);
	switch(opcao){
		case 'S':
			quick_sort(elementos,0, tam-1);
			break;
		case 'N':
			return EXIT_SUCCESS;
			break;
		default:
			cout << "Opção invalida" << endl;
	}

	for(int i = 0 ; i< tam; i++){

		cout << elementos[i]<<" ";

	}	cout << endl;		
}



