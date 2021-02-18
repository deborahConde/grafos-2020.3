/*     IMPLEMENTACAO DO TAD GRAFO       */

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include <fstream>
#include <stack>
#include <list>

using namespace std;

class Grafo {
	private:
		int ordem;
		int numero_arestas;
		bool direcionado;
		bool arestaComPeso;
		bool noComPeso;
		No* primeiro_no;
		No* ultimo_no;
        int numNos;
	

	public:
        //Construtor
        Grafo(int ordem, bool direcionado, bool arestaComPeso, bool noComPeso);
        //Destructor
        ~Grafo();
        //Gets
        int getOrdem();
        int getNumeroArestas();
        bool getDirecionado();
        bool getArestaComPeso();
        bool getNoComPeso();
        No* getPrimeiroNo();
        No* getUltimoNo();
        int getIndexNo(int id);
        //Outros metodos
        void inserirNo(int id);
        void inserirAresta(int id, int target_id, float peso);
        void removerNo(int id);
        bool buscaNo(int id);
        void colocarNoInicio(No* no);
        No* getNo(int id);
        void printGrafo();

        //methods phase1
        Grafo* subgrafoInduzido(int* ids, int tam,int direcionado,int arestaComPeso,int noComPeso);

        void topologicalSorting();
        void breadthFirstSearch(ofstream& output_file);
        Grafo* getVertexInduced(int* listIdNodes);
        Grafo* agmKuskal();
        Grafo* agmPrim();
        float floydMarshall(int idSource, int idTarget);
        float dijkstra(int idSource, int idTarget);
        int min_distance(int* dist, bool* visited);

        //methods phase2
        float greed();
        float greedRandom();
        float greedRactiveRandom();
private:
    //Auxiliar methods

};


#endif // !GRAFO_H_INCLUDED
