#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#include "./include/Cards.h"
#include "./include/PilhaEncadeada.h"
#include "./include/ListaEncadeada.h"
#include "./include/game.h"

Pilha::Pilha()
{
    head = new Head;
    head->topo = NULL;
    head->tamanho = 0;
}

void Pilha::inclui(Cards *valor)
{
    No * no = new No;
    no->trunfo2 = valor;
    no->prox = NULL;
    if (head->tamanho == 0) {
        no->ant = NULL;
    } else {
        no->ant = head->topo;
        (head->topo)->prox = no;
    }
    head->tamanho ++;
    head->topo = no;
}

// FUNÇÃO PARA PRINTAR E REMOVER A CARTA
void Pilha::remover()
{
    cout <<"\t\t\t╔═══════════════════════════════════╗\n";
    cout <<"\t\t\t║           Super trunfo !          ║\n";   
    cout <<"\t\t\t║               Carta      	    ║\n";
    cout <<"\t\t\t╚═══════════════════════════════════╝\n";
    cout <<"\t\t\t""Tipo da carta: " <<(head->topo)->trunfo2->get_card_type()  <<" \n";
    cout <<"\t\t\t""Nome do carro: " << (head->topo)->trunfo2->get_nome() <<  "\n";
    cout <<"\t\t\t""Velocidade Max: " << (head->topo)->trunfo2->get_vel_max() << " Km/h \n";
    cout <<"\t\t\t""Potencia: " << (head->topo)->trunfo2->get_potencia() << " CV \n";
    cout <<"\t\t\t""Torque: " << (head->topo)->trunfo2->get_torque() << "  \n";
    cout <<"\t\t\t""preco R$: " << (head->topo)->trunfo2->get_preco() << " Mil	\n\n"; 

    if(head->tamanho > 1) {
        head->topo = (head->topo)->ant ;
        delete (head->topo)->prox;
        (head->topo)->prox = NULL;
        head->tamanho --;
    } else if(head->tamanho == 1) {
        delete head->topo;
        head->topo = NULL;
        head->tamanho = 0;
    } else if(head->tamanho == 0) {
        cout << "Pilha já está vazia\n";
    }
}

void Pilha::imprime()
{
    if(head->tamanho == 0) {
        cout << "\n A Pilha esta vazia \n";
    } 
    else 
    {


    cout << "\n";
    cout << "\t\t\t\t      NOVA CARTA!\t\n";
    cout <<"\t\t\t╔═══════════════════════════════════╗\n";
    cout <<"\t\t\t║           Super trunfo !          ║\n";   
    cout <<"\t\t\t║               Carta      	    ║\n";
    cout <<"\t\t\t╚═══════════════════════════════════╝\n";
    cout <<"\t\t\t""Tipo da carta:	" <<(head->topo)->trunfo2->get_card_type()  <<" \n";
    cout <<"\t\t\t""Nome do carro:	" << (head->topo)->trunfo2->get_nome() <<  "\n";
    cout <<"\t\t\t""Velocidade Max:	" << (head->topo)->trunfo2->get_vel_max() << " Km/h \n";
    cout <<"\t\t\t""Potencia:	" << (head->topo)->trunfo2->get_potencia() << " CV \n";
    cout <<"\t\t\t""Torque: " << (head->topo)->trunfo2->get_torque() << "  \n";
    cout <<"\t\t\t""preco R$:	" << (head->topo)->trunfo2->get_preco() << " Mil	\n\n"; 
    }

}

Cards* Pilha::lerDado()
{
    cout << "\n valor a ser movido " << (head->topo)->trunfo2;
    return (head->topo)->trunfo2;
}
