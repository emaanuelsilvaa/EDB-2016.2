#include <iostream>

using namespace std;

struct vetor{

	int tam;
	int* elementos;

};
/** -----------------------------------------------------------
* Dado um vetor de tamanho n, após a execução desta função,
* os elementos do vetor estarão ordenados em ordem crescente.
*
* @param	v - uma struct contendo um vetor e seu tamanho
*
* @pre v.tam > 0
* @post para cada elemento v[i] em 'v.elementos', será verdadeiro
* que v[i] <= v[i+1].
*/
void buble_sort(vetor v){
	
	int aux;	

	for ( int i = v.tam-1; i >= 1 ; i--){
		
		for(int j{0} ; j < i ; j++) {
			
			if (v.elementos[j]>v.elementos[j+1]){
				
				aux = v.elementos[j];
				v.elementos[j] = v.elementos[j+1];
				v.elementos[j+1] = aux;
	
			}

		}
		
	}

	for(int i{0} ; i < v.tam ; i++) {
		
		cout << v.elementos[i] << " ";

	}
	
	cout << endl;

}

//-------------------------------------------------------------------

/** -----------------------------------------------------------
* Dado um vetor de tamanho n, e a faixa de numero aleatorios a ser
* colocados no vetor, após a execução desta função,
* os elementos do vetor estarão ordenados em ordem crescente.
*
* 
*
* @pre faixa > 0 
* @post para cada elemento v[i] em 'v.elementos', será verdadeiro
* que v[i] <= v[i+1].
*/

int main (int argc, char** argv){

	srand(time(NULL));

	int n, faixa;

	char opcao;

	vetor v;	

	cout << "digite o tamanho do vetor : " << endl;
	cin >> v.tam;
	cout << "Digite a faixa de numeros aleatorios a ser colocados no vetor" << endl;
	cin >> faixa;

	for(int i{0} ; i < v.tam ; i++){
		v.elementos[i] = rand() % faixa;
		cout << v.elementos[i] << " ";
	} 
	
	cout << endl << "Deseja ordenar o vetor com o algoritmo BUBBLE_SORT ?  [S/N]" << endl;
	
	 cin >> opcao;
	 opcao=toupper(opcao);

	switch(opcao){
		case 'S':
			buble_sort(v);
			break;
		case 'N':
			return EXIT_SUCCESS;
			break;
		default:
			cout << "Opção invalida" << endl;
	}			

}


