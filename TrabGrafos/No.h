/*     IMPLEMENTACAO DO TAD NO       */

#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "Aresta.h" //Inclui a classe aresta

using namespace std;

//Definição da classe NO
class No {

	private:
        Aresta* primeira_aresta;
        Aresta* ultima_aresta;
        int id;
        unsigned int in_degree;
        unsigned int out_degree;
        float peso;
        No* prox_no;
    public:
        //Construtor
        No(int id);
        //Destrutor
        ~No();
        //Gets
        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        int getId();
        int getInDegree();
        int getOutDegree();
        float getPeso();
        No* getProxNo();
        //Sets
        void setProxNo(No* No);
        void setPeso(float peso);
        //Outros Metodos
        bool buscaAresta(int target_id);
        void inserirAresta(int target_id, float peso);
        void removerTodasArestas();
        int removerAresta(int id, bool direcionada, No* target_no);
        void incrementOutDegree();
        void decrementOutDegree();
        void incrementInDegree();
        void decrementInDegree();
        Aresta* temArestaEntre(int target_id);
        //Metodos Auxiliares
            //Implementar quando nescessario

};


#endif 

