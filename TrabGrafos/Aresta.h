/*     IMPLEMENTACAO DO TAD ARESTA       */

#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

using namespace std;

//Definicao da classe aresta
class Aresta {

	private:
		int target_id;
		Aresta* prox_aresta;
		float peso;

	public:
		// Construtor
		Aresta(int target_id);
		// Destrutor
		~Aresta();
		//Gets
		int getTargetId();
		Aresta* getProxAresta();
		float getPeso();
		//Sets
		void setNextAresta(Aresta* aresta);
		void setPeso(float peso);

};


#endif
