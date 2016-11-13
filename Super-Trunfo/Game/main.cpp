#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "./include/Cards.h"
#include "./include/PilhaEncadeada.h"
#include "./include/ListaEncadeada.h"
#include "./include/game.h"

using namespace std;

int main ()
{

	Lista *trunfo = new Lista;
 
 	// 
	inserir_lista(trunfo);

	Pilha jogador1;
	Pilha jogador2;


	// ICLUINDO AS CARTAS NA PILHA DE CADA JOGADOR
	for(int i{0} ; i < 20 ; i++)
	{
		jogador1.inclui(trunfo->buscar(rand() % 20));
	}

	for(int i{0} ; i < 20 ; i++)
	{
		jogador2.inclui(trunfo->buscar(rand() % 20));
	}
	menu(trunfo,jogador1,jogador2);
}
