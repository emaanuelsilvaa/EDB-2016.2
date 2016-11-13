#ifndef __PILHA_ENCADEADA_H_
#define __PILHA_ENCADEADA_H_
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*-------------------------------------------------------
---------------------------------------------------------
-------------------- PILHA ENCADEADA --------------------
-------------------- PILHA ENCADEADA --------------------
---------------------------------------------------------
---------------------------------------------------------
*/
struct No {
    Cards *trunfo2;
    No* prox;
    No* ant;
};

struct Head {
    int tamanho;
    No* topo;
};

class Pilha
{
private:

public:
    Head * head;
    int pontos = 0;
    Pilha();
    void inclui(Cards* trunfo2);
    void remover();
    void imprime();
    Cards* lerDado();
};

#endif
