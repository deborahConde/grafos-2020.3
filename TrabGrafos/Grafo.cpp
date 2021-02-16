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

void Grafo::printGrafo() {
	No* no = this->primeiro_no;
	Aresta* aresta;
	while (no != nullptr)
	{
		cout << no->getId() << ": ";
		aresta = no->getPrimeiraAresta();
		if (aresta != nullptr) {
			while (aresta != nullptr)
			{
				cout << "-->" << aresta->getTargetId();
				aresta = aresta->getProxAresta();
			}
		}
		no = no->getProxNo();
		cout << endl;
	}
}

void Grafo::inserirNo(int id) {
	No* prox;
	No* aux = nullptr;
	if (this->primeiro_no == nullptr)
	{
		this->primeiro_no = new No(id);
	}
	else
	{

		prox = this->primeiro_no;

		while (prox != nullptr)
		{
			aux = prox;
			prox = prox->getProxNo();

		}
		aux->setProxNo(new No(id));

	}
	
}

void Grafo::inserirAresta(int id, int target_id, float peso) {

	No* no = this->primeiro_no;
	
	

	while (no->getId() != id) {
		no = no->getProxNo();
	}
	no->inserirAresta(target_id, peso);

	no->incrementOutDegree();

	//caso o grafo nao seja direcionado, adicionar a aresta tambem ao vertice de chegada
	if (!this->direcionado) {
		no = this->primeiro_no;

		while (no->getId() != target_id) {
			no = no->getProxNo();
		}
		no->inserirAresta(id, peso);
		no->incrementInDegree();
	}

	this->numero_arestas++;
}


void Grafo::removerNo(int id) {
	No* no;
	No* noAux = new No(id);
	No* anterior;

	for (no = this->primeiro_no; no != nullptr; no = no->getProxNo())
	{
		no->removerAresta(id, 0, noAux);
	}

	no = this->primeiro_no;

	//se o no a ser excluido for o primeiro na lista
	if (no->getId() == id) {
		this->primeiro_no = no->getProxNo();
		no->removerTodasArestas();
		delete no;
		return;
	}
	//anterior recebe o primeiro
	anterior = no;
	for (no = no->getProxNo(); no != nullptr; no = no->getProxNo())
	{	
		//no = o proximo depois do anterior
		if (no->getId() == id) {
			anterior->setProxNo(no->getProxNo());
			no->removerTodasArestas();
			delete no;
			return;
		}
		//anterior = no atual antes da proxima iteracao
		anterior = no;
	}
}


bool Grafo::buscaNo(int id) {
	No* no;
	for (no = this->primeiro_no; no != nullptr ; no = no->getProxNo())
	{
		if (no->getId() == id)
			return true;
	}

	return false;
}

No* Grafo::getNo(int id) {
	if (buscaNo(id))
	{
		No* no;
		for (no = this->primeiro_no; no != nullptr; no = no->getProxNo())
		{
			if (no->getId() == id)
				return no;
		}
	}

	return nullptr;
}

//Function that prints a set of edges belongs breadth tree



Grafo* Grafo::subgrafoInduzido(int* ids, int tam) {
	
	Grafo* subgrafoInduzido= new Grafo(tam,0,0,0);
	No* no;


	//inserir todos os nos do subgrafo induzido
	for (int i = 0; i < tam; i++)
	{
		for (no = this->primeiro_no; no != nullptr; no = no->getProxNo())
		{		
			if (no->getId() == ids[i]) {
				subgrafoInduzido->inserirNo(no->getId());
			}
		}
	}

	//inserir todas as arestas no subgrafo induzido
	
	no = this->primeiro_no;
	for (int i = 0; i < tam; i++)
	{
		if (subgrafoInduzido->buscaNo(no->getId())) {
			for (int j = 0; j < tam; j++)
			{

				if (no->buscaAresta(ids[j])) {
					subgrafoInduzido->inserirAresta(no->getId(), ids[j], 0);
				}

			}
		}
		no = no->getProxNo();
	}
	
	return subgrafoInduzido;
	
}

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
