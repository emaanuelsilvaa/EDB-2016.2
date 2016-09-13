#include <iostream>

using namespace std;

void merge(int vetor[], int tamanho, int esquerda, int meio, int direita){

	int temp[tamanho];
	for(int i = esquerda ; i <= direita ; i++){

		temp[i] = vetor[i];

	}
	int i = esquerda;
	int j = meio + 1;
	int k = esquerda;
	while(i <= meio and j <= direita){

		if(temp[i] <= temp[j]){
	
			vetor[k] = temp[i];
			i++;
		}
		else{
			vetor[k] = temp[j];
			j++;
		}
		k++;
	}
	while(i <= meio){
		vetor[k] = temp[i];
		k++;
		i++;
	}
	while(j <= direita){
		vetor[k] = temp[j];
		k++;
		j++;
	}
}
/** -----------------------------------------------------------
* Dado um vetor de tamanho n, após a execução desta função,
* os elementos do vetor estarão ordenados em ordem crescente.
*
* @param	vetor 
* @param	tamanho ( informa o tamanho do vetor)
* @param	esquerda (indica o inicio do vetor)
* @param	direita (indica o fim do vetor)
* 
* 
* @pre tamanho > 0
* @post para cada elemento v[i] em 'vetor', será verdadeiro
* que v[i] <= v[i+1].
*/
void intercalar(int vetor[], int tamanho, int esquerda, int direita){
	
	if(esquerda < direita){
		int meio = (esquerda + direita)/2;
		intercalar(vetor, tamanho, esquerda, meio);
		intercalar(vetor, tamanho, meio+1, direita);
		merge(vetor, tamanho, esquerda, meio, direita);
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
	cout << endl << "Deseja ordenar o vetor com o algoritmo INSERTION_SORT ?  [S/N]" << endl;
	cin >> opcao;

	opcao = toupper(opcao);
	switch(opcao){
		case 'S':
			intercalar(elementos,tam,0, tam-1);
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
