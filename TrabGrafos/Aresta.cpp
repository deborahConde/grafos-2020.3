/*   DEFININDO OS METODOS DE "ARESTA.H"   */

#include "Aresta.h"
#include "iostream"

using namespace std;

//Construtor
Aresta::Aresta(int target_id) {
	this->target_id = target_id;
	this->prox_aresta = nullptr;
	this->peso = 0;
}

//Destrutor
Aresta::~Aresta() {
	if (this->prox_aresta != nullptr) {
		delete this->prox_aresta;
		this->prox_aresta = nullptr;
	}
}

//Gets
int Aresta::getTargetId() {
	return this->target_id;
}

Aresta* Aresta::getProxAresta() {
	return this->prox_aresta;
}

float Aresta::getPeso() {
	return this->peso;
}

//Sets

void Aresta::setNextAresta(Aresta* aresta) {
	this->prox_aresta = aresta;
}

void Aresta::setPeso(float peso) {
	this->peso = peso;
}