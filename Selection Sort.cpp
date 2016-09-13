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
void selection_sort(vetor v) 
{ 
  int i, j, min, aux;
  for (i = 0; i < (v.tam-1); i++) 
   {
    min = i;
    for (j = (i+1); j < v.tam; j++) {
      if(v.elementos[j] < v.elementos[min]) 
        min = j;
    }
    if (i != min) {
      aux = v.elementos[i];
      v.elementos[i] = v.elementos[min];
      v.elementos[min] = aux;
    }
  }

	for(int i{0} ; i < v.tam ; i++) {
		
		cout << v.elementos[i] << " ";
	}
		cout << endl;
}

//------------------------------------------------------------------

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
	
	cout << endl << "Deseja ordenar o vetor com o algoritmo SELECTIO_SORT ?  [S/N]" << endl;
	
	 cin >> opcao;
	 opcao=toupper(opcao);

	switch(opcao){
		case 'S':
			selection_sort(v);
			break;
		case 'N':
			return EXIT_SUCCESS;
			break;
		default:
			cout << "Opção invalida" << endl;
	}			

}


