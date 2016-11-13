#ifndef _CARDS_H_
#define _CARDS_H_
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
	Cards();
	Cards(int indice, string nome, int vel_max, float preco, int potencia, float torque, string card_type);
	
	void set_indice(int indice); 
	int get_indice(); 

	void set_nome(string nome);  
	string get_nome(); 

	void set_vel_max(int vel_max);  
	int get_vel_max(); 

	void set_preco(int preco);  
	float get_preco(); 

	void set_potencia(int potencia);  
	int get_potencia(); 

	void set_torque(int torque); 
	float get_torque();
 	
	void set_card_type(string card_type);  
	string get_card_type(); 

};

#endif
