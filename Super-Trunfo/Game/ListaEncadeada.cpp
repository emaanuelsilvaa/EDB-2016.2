#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "./include/Cards.h"
#include "./include/PilhaEncadeada.h"
#include "./include/ListaEncadeada.h"
#include "./include/game.h"

using namespace std;

	void Lista::inserir(Cards *trunfo) // inserindo um novo nó( um dado na lista)
	{
		node *aux = new node;  //  criando alocando um nó auxiliar ( sempre que eu chamar está função eu irei criar um nó (um dado na lista))
		aux->trunfo = trunfo; //  esse meu novo dado(aux) vai receber o dado que eu passei em inserir
		aux->prox = NULL;	 //  logo o meu novo dado que é do tipo no vai fazer  com que o nó prox aponte ara nulo 
		if (cabeca == NULL)	// aqui verefica-se se cabeça é nulo que se refenrencia a uma lista vazia
		{
			cabeca = aux; // se cabeça for nulo eu crio o meu primeiro dado da lista e faço cabeça apontar para o meu primeiro dado (aux)
			rabo = aux; // o rabo se refencia a ultima posição da lista, logo estarei inserindo o dado sempre no rabo.
		}else // no caso de ter mais de um dado .. 
		{
			rabo->prox = aux; // rabo que é do tipo node tem seu ponteiro proximo apontado para o novo dado(aux)
			rabo = aux;	// o novo dado deve ter apontando tanto o rabo quanto o rabo->prox
		}
	}

	void Lista::remover(int indice) // removendo um dado.
	{
		if (cabeca == NULL) // verifica se a lista esta vazia
		{
			return;
		}
		node *aux; // cria um nó auxiliar para esse nó manter o endereço do ultimo dado para que essa endereço nao seja perdido
		aux = cabeca; 	// será copiado o endereço da cabeça para um nó auxiliar
		node *ant = NULL; // cria-se um nó ant e aponta para nulo



		if(indice == cabeca->trunfo->get_indice()) // verefica se o indice passado é igual ao indice da cabeça que pode ser visto como o primeiro indice da lista
		{
			cabeca = cabeca->prox; // caso for igual, cabeça vai apontar para o endereço do proximo,  
			
			delete aux; // deletando o aux
			return;

		}
		while ( aux != NULL ) // pecorrendo a lista
		{
			if (aux->trunfo->get_indice() ==  indice) // se o indice for igual a o indice da cabeça
			{
				if (ant == NULL) // se ant for ingual a null que se refere a o indice se o primeiro
				{
					cabeca = aux->prox; // cabeça é apontado para o proximo elemento

				}if (aux->prox == NULL)
				{
					ant->prox = aux->prox;	
				}
				else // se nao
				{
					ant->prox = aux->prox; // anterior que de inicio é nulo tera que ser
				}
				delete aux;
				return;

			}
			ant = aux;
			aux = aux->prox;
		}

	}

	Cards* Lista::buscar(int indice)
	{
		
		node *aux = cabeca;
		while(aux != NULL)
		{
			if(indice == aux->trunfo->get_indice())
			{
				return aux->trunfo;
			}
			aux = aux->prox;
		} 
		return 0;
	}

