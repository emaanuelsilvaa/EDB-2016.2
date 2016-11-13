#include <iostream>
#include <time.h>
#include <stdlib.h>


#include "./include/Cards.h"
#include "./include/PilhaEncadeada.h"
#include "./include/ListaEncadeada.h"
#include "./include/game.h"

using namespace std;

	Cards::Cards()
	{
		this->indice = 0;
		this->nome = "0";
		this->vel_max = 0;
		this->preco = 0;
		this->potencia = 0;
		this->torque = 0;
		this->card_type = "0";
	}
	Cards::Cards(int indice, string nome, int vel_max, float preco, int potencia, float torque, string card_type)
	{
		this->indice = indice;
		this->nome = nome;
		this->vel_max = vel_max;
		this->preco = preco;
		this->potencia = potencia;
		this->torque = torque;
		this->card_type = card_type;	
	}

	void Cards::set_indice(int indice) { this->indice = indice;	} 
	int Cards::get_indice() { return this->indice; }

	void Cards::set_nome(string nome) { this->nome = nome; } 
	string Cards::get_nome() { return this->nome; }

	void Cards::set_vel_max(int vel_max) { this->vel_max = vel_max; } 
	int Cards::get_vel_max() { return this->vel_max; }

	void Cards::set_preco(int preco) { this->preco = preco; } 
	float Cards::get_preco() { return this->preco; }

	void Cards::set_potencia(int potencia) { this->potencia = potencia; } 
	int Cards::get_potencia() { return this->potencia; }

	void Cards::set_torque(int torque) { this->torque = torque; } 
	float Cards::get_torque() { return this->torque; }
	
	void Cards::set_card_type(string card_type) { this->card_type = card_type; } 
	string Cards::get_card_type() { return this->card_type;}