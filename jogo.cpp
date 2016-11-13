#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*-------------------------------------------------------
---------------------------------------------------------
-------------------- CLASS DA CARTA ---------------------
-------------------- CLASS DA CARTA ---------------------
---------------------------------------------------------
---------------------------------------------------------
*/
class Cards{
private:
	int indice;
	string nome;
	int vel_max;
	float preco;
	int potencia;
	float torque;
	string card_type;


public:
	Cards()
	{
		this->indice = 0;
		this->nome = "0";
		this->vel_max = 0;
		this->preco = 0;
		this->potencia = 0;
		this->torque = 0;
		this->card_type = "0";
	}
	Cards(int indice, string nome, int vel_max, float preco, int potencia, float torque, string card_type)
	{
		this->indice = indice;
		this->nome = nome;
		this->vel_max = vel_max;
		this->preco = preco;
		this->potencia = potencia;
		this->torque = torque;
		this->card_type = card_type;	
	}

	void set_indice(int indice) { this->indice = indice;	} 
	int get_indice() { return this->indice; }

	void set_nome(string nome) { this->nome = nome; } 
	string get_nome() { return this->nome; }

	void set_vel_max(int vel_max) { this->vel_max = vel_max; } 
	int get_vel_max() { return this->vel_max; }

	void set_preco(int preco) { this->preco = preco; } 
	float get_preco() { return this->preco; }

	void set_potencia(int potencia) { this->potencia = potencia; } 
	int get_potencia() { return this->potencia; }

	void set_torque(int torque) { this->torque = torque; } 
	float get_torque() { return this->torque; }
	
	void set_card_type(string card_type) { this->card_type = card_type; } 
	string get_card_type() { return this->card_type;}

};

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
		Cards *trunfo;	// dados da lista encadeada
		node *prox;		// ponteiro apontando proximo no ( que pode ser considerado o outro indice de um vetor)
	};
	node *cabeca = NULL; // ponteniro referenciando a o inicio da lista
	node *rabo = NULL;		// ponteiro referenciando 

public:
	//~lista();
	
	void inserir(Cards *trunfo) // inserindo um novo nó( um dado na lista)
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

	void remover(int indice) // removendo um dado.
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

	Cards* buscar(int indice)
	{
		
		node *aux = cabeca;
		while(aux != NULL)
		{
			//cout << aux->trunfo->get_indice() << endl;
			if(indice == aux->trunfo->get_indice())
			{
				//cout << "helo";
				//cout << "Indice da carta: "<< aux->trunfo->get_indice() << endl;
				//cout << "Ataque: " <<  aux->trunfo->get_ataque() << endl;
				//cout << "Defesa: " << aux->trunfo->get_defesa() << endl;
				return aux->trunfo;
				//cout << aux->trunfo << endl;
			}
			aux = aux->prox;

		} 
		
		return 0;
	}

};

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


void inserir_lista(Lista *trunfo)
{
	trunfo->inserir(new Cards(0, "Fiat Uno", 179, 22.000, 80, 9.5, "A1"));
	trunfo->inserir(new Cards(1, "Golf 2016", 180, 46.000, 120, 9.7, "A2"));
	trunfo->inserir(new Cards(2, "Palio 2015", 175, 22.300, 88, 9.8, "A3"));
	trunfo->inserir(new Cards(3, "FordKa 2017", 160, 27.100, 86, 9.6, "A4"));
	trunfo->inserir(new Cards(4, "Fusca 1987", 166, 10.500, 77, 9.9, "A5"));
	trunfo->inserir(new Cards(5, "Kombi 1998", 165, 33.700, 76, 9.1, "A6"));
	trunfo->inserir(new Cards(6, "Celta  2012", 170, 25.800, 80, 9.2, "A7"));
	trunfo->inserir(new Cards(7, "Parati 1999", 190, 20.400, 89, 8.8, "A8"));
	trunfo->inserir(new Cards(8, "Honda Civic 2015", 200, 44.050, 110, 8.9, "A9"));
	trunfo->inserir(new Cards(9, "HB20 2016", 199, 45.500, 101, 8.7, "B2"));
	trunfo->inserir(new Cards(10, "Siena 2015", 189,33.600, 102, 8.6,"B5" ));
	trunfo->inserir(new Cards(11, "Corsa sedan 2015", 191, 32.600, 105, 8.5,"B6" ));
	trunfo->inserir(new Cards(12, "Chevrolet Cruze 2014", 220, 55.300, 122, 8.3, "B3" ));
	trunfo->inserir(new Cards(13, "Gol 2014", 188, 35.000, 99, 8.2, "B1"));
	trunfo->inserir(new Cards(14, "Fiat Punto", 197, 40.000, 107, 10.0, "B9"));
	trunfo->inserir(new Cards(15, "Camaro 2017", 225, 120.000, 150, 11.0, "S1"));
	trunfo->inserir(new Cards(16, "Amarok 2015", 210, 80.000, 151, 11.2, "S3"));
	trunfo->inserir(new Cards(17, "Gol Voyage 2016", 196, 35.000, 110, 10.6,"S6" ));
	trunfo->inserir(new Cards(18, "Ford new fiesta 2016", 188, 40.000, 109, 9.2, "S9"));
	trunfo->inserir(new Cards(19, "Audi A3 2015", 210, 35.700, 122, 10.4, "B8" ));
	trunfo->inserir(new Cards(20, "Citroem C3 2015", 191, 22.500, 123, 10.2, "D3" ));

}


/*Codigo retiado da internet para fazer um delay, para os valores da randTo serem diferentes.
** <https://www.vivaolinux.com.br/topico/C-C++/Executando-em-segundo-plano>
*/
void pause (float delay1) {                                                                 //
                                                                                            //
   if (delay1<0.0001) return;   // pode ser ajustado e/ou evita-se valores negativos.       //
                                                                                            //
   float inst1=0, inst2=0;                                                                  //
                                                                                            //
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;                                            //
                                                                                            //
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;                 //
}

 
void game(Lista *trunfo, Pilha jogador1, Pilha jogador2)
{
	while (jogador1.pontos < 100 or jogador2.pontos < 100)
	{
		int n, ia;
		if(jogador1.pontos == 100)
		{
			pause(2.5);
			cout << "voce ganhou o jogo!\n";
			cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos;
			exit(EXIT_FAILURE);
		}
		else if ( jogador2.pontos == 100)
		{
			pause(2.5);
			cout << "\nComputador ganhou o jogo !\n";
			cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos << endl;

			exit(EXIT_FAILURE);
		}
		
		if ( ia == 10)
		{
			n = rand() % 3;
			printf("\033[2J");

		}
		else{
			jogador1.imprime();

			cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos;
			cout << "\n1- velocidade\n";
			cout << "2- potencia\n";
			cout << "3- torque\n";
			cout << "4- Preco\n";
			cout << "digite umas das opções\n";
			cin >> n;
			printf("\033[2J");
			
		}

		switch(n-1){

			case 0:
				if (jogador1.head->topo->trunfo2->get_vel_max() > jogador2.head->topo->trunfo2->get_vel_max())
				{
					cout << "Voce ganhou a rodada !\n";
					jogador1.pontos = jogador1.pontos + 10;
					jogador1.remover();
					jogador2.remover();
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					ia = 0;
					pause(2.7);
				} 
				else
				{
					cout << "O computador está comparando as velocidades dos carros\n";
					jogador1.remover();
					jogador2.remover();
					pause(3.1);
					cout << "computador ganhou a rodada!\n";
					cout << "vez do computador\n";
					cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos << "\n";
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					jogador2.pontos = jogador2.pontos + 10;	
					ia = 10;
					pause(3.1);

							
				}
				break;
			case 1:
				if (jogador1.head->topo->trunfo2->get_potencia() > jogador2.head->topo->trunfo2->get_potencia())
				{
					cout << "Voce ganhou a rodada !\n";
					jogador1.pontos = jogador1.pontos + 10;
					jogador1.remover();
					jogador2.remover();
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					ia = 0;
					pause(2.7);
				} 
				else
				{
					cout << "O computador está comparando as potencias dos carros\n";
					jogador1.remover();
					jogador2.remover();
					pause(3.1);
					cout << "\ncomputador ganhou a rodada!\n";
					cout << "vez do computador\n";
					cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos << "\n";
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					jogador2.pontos = jogador2.pontos + 10;	
					ia = 10;
					pause(3.1);
				}	
				break;

			case 2:
				if (jogador1.head->topo->trunfo2->get_torque() > jogador2.head->topo->trunfo2->get_torque())
				{
					cout << "Voce ganhou a rodada !\n";
					jogador1.pontos = jogador1.pontos + 10;
					jogador1.remover();
					jogador2.remover();
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					ia = 0;
					pause(2.7);
				} 
				else
				{
					cout << "O computador está comparando o torque dos carros\n";
					jogador1.remover();
					jogador2.remover();
					pause(3.1);
					cout << "\ncomputador ganhou a rodada!\n";
					cout << "vez do computador\n";
					cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos << "\n";
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					jogador2.pontos = jogador2.pontos + 10;
					ia = 10;
					pause(3.1);
				}
				break;

			case 3:
				if (jogador1.head->topo->trunfo2->get_preco() > jogador2.head->topo->trunfo2->get_preco())
				{
					cout << "Voce ganhou a rodada !\n";
					jogador1.pontos = jogador1.pontos + 10;
					jogador1.remover();
					jogador2.remover();
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					ia = 0;
					pause(2.5);
				} 
				else
				{
					cout << "O computador está comparando os preços dos carros\n";
					jogador1.remover();
					jogador2.remover();
					pause(3.1);
					cout << "\ncomputador ganhou a rodada!\n";
					cout << "vez do computador\n";
					cout << "Seus Pontos: " << jogador1.pontos << "\t║ " << "Pontos do adversario: " << jogador2.pontos << "\n";
					jogador1.inclui(trunfo->buscar(rand() % 20));
					jogador2.inclui(trunfo->buscar(rand() % 20));
					jogador2.pontos = jogador2.pontos + 10;	
					ia = 10;
					pause(3.1);
					break;
				}
			default:
			break;
		}


	}
}   


void menu(Lista *trunfo, Pilha jogador1, Pilha jogador2){        //Menu inicial
    
    cout <<"\t\t\t╔═════════════════════════════════════════╗\n";
    cout <<"\t\t\t║             Super trunfo !              ║\n";   
    cout <<"\t\t\t║              Bem Vindo!!                ║\n";
    cout <<"\t\t\t╠═════════════════════════════════════════╣\n";
    cout <<"\t\t\t║                                         ║\n";
    cout <<"\t\t\t║              1 - Jogar                  ║\n";
    cout <<"\t\t\t║              3 - Como jogar             ║\n";
    cout <<"\t\t\t║              4 - creditos               ║\n";
    cout <<"\t\t\t║              5 - Sair                   ║\n"; 
    cout <<"\t\t\t╚═════════════════════════════════════════╝\n";


    int n;
        
    printf("---->");
    cin >> n;
    
    switch(n){    
        case(1):
        printf("\033[2J");
        game(trunfo,jogador1,jogador2);
        break;        
    
        case(2):
        break;
    
        case(3):
        break;
    
        case(4):
        break;
        case(5):
        exit(EXIT_FAILURE);
        break;
        default:
            printf("Informe um valor valido\n");
            pause(2.1);
            menu(trunfo,jogador1,jogador2); 
            break;
    }          
}




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














