#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "./include/Cards.h"
#include "./include/PilhaEncadeada.h"
#include "./include/ListaEncadeada.h"
#include "./include/game.h"

using namespace std;



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