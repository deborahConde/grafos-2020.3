/*   DEFININDO OS METODOS DE "GRAFO.H"   */

#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>

using namespace std;

// Construtor
Grafo::Grafo(int ordem, bool direcionado, bool arestaComPeso, bool noComPeso) {
	this->ordem = ordem;
	this->direcionado = direcionado;
	this->arestaComPeso = arestaComPeso;
	this->noComPeso = noComPeso;
	this->primeiro_no = this->ultimo_no = nullptr;
	this->numero_arestas = 0;
}

//Destrutor
Grafo::~Grafo() {
	No* proxNo = this->primeiro_no;
	while (proxNo != nullptr)
	{
		proxNo->removerTodasArestas();
		No* auxNo = proxNo->getProxNo();
		delete proxNo;
		proxNo = auxNo;
	}
}

//Gets
int Grafo::getOrdem() {
	return this->ordem;
}

int Grafo::getNumeroArestas() {
	return this->numero_arestas;
}

//Funcao que verifica se o grafo é direcionado
bool Grafo::getDirecionado()
{
	return this->direcionado;
}

//Funcao que verifica se as arestas tem peso
bool Grafo::getArestaComPeso() {
	return this->arestaComPeso;
}

//Funcao que verifica se o no tem peso
bool Grafo::getNoComPeso() {
	return this->noComPeso;
}

No* Grafo::getPrimeiroNo() {
	return this->primeiro_no;
}
No* Grafo::getUltimoNo() {
	return this->ultimo_no;
}

/*************************************************************************************************************/

	//					IMPLEMENTACAO COMECA A PARTIR DAQUI 

/*************************************************************************************************************/


//Outros Metodos

/*
	The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
	This allows the correct updating of the numbers of edges in the graph being directed or not.
*/

void Grafo::inserirNo(int id) {

}

void Grafo::inserirAresta(int id, int target_id, float peso) {

}

void Grafo::removerNo(int id) {

}

bool Grafo::buscaNo(int id) {
	return false;
}

No* Grafo::getNo(int id) {
	return nullptr;
}

//Function that prints a set of edges belongs breadth tree

void Grafo::breadthFirstSearch(ofstream& output_file) {

}



float Grafo::floydMarshall(int idSource, int idTarget) {
	return 0;
}



float Grafo::dijkstra(int idSource, int idTarget) {
	return 0;
}

//function that prints a topological sorting
void topologicalSorting() {

}

void breadthFirstSearch(ofstream& output_file) {

}
Grafo* getVertexInduced(int* listIdNodes) {
	return nullptr;
}

Grafo* agmKuskal() {
	return nullptr;
}
Grafo* agmPrim() {
	return nullptr;
}
