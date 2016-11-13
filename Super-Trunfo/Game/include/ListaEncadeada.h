#ifndef __LISTA_ENCADEADA_H_
#define __LISTA_ENCADEADA_H_
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*-------------------------------------------------------
---------------------------------------------------------
-------------------- LISTA ENCADEADA --------------------
-------------------- LISTA ENCADEADA --------------------
---------------------------------------------------------
---------------------------------------------------------
*/
class Lista
{
private:
	struct node {
		Cards *trunfo;
		node *prox;		
	};
	node *cabeca = NULL; 
	node *rabo = NULL;		 
public:
	void inserir(Cards *trunfo);
	void remover(int indice);
	Cards* buscar(int indice);
};



#endif
