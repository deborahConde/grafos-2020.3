/*   DEFININDO OS METODOS DE "NO.H"   */

#include "No.h"
#include "Aresta.h"
#include "iostream"

using namespace std;

//Construtor
No::No(int id) {
    this->id = id;
    this->in_degree = 0;
    this->out_degree = 0;
    this->peso = 0;
    this->primeira_aresta = nullptr;
    this->ultima_aresta = nullptr;
    this->prox_no = nullptr;
}


// Destrutor
No::~No() {

    Aresta* proxAresta = this->primeira_aresta;

    while (proxAresta != nullptr) {

        Aresta* auxAresta = proxAresta->getProxAresta();
        delete proxAresta;
        proxAresta = auxAresta;

    }

};


// Gets
Aresta* No::getPrimeiraAresta() {

    return this->primeira_aresta;

}

Aresta* No::getUltimaAresta() {

    return this->ultima_aresta;

}

int No::getId() {

    return this->id;

}

int No::getInDegree() {

    return this->in_degree;

}

int No::getOutDegree() {

    return this->out_degree;

}

float No::getPeso() {

    return this->peso;

}

No* No::getProxNo() {

    return this->prox_no;

}


// Sets
void No::setProxNo(No* prox_no){

    this->prox_no = prox_no;

}

void No::setPeso(float peso){

    this->peso = peso;

}

//Outros Metodos
void No::inserirAresta(int target_id, float peso) {
    //Verifica se tem pelo menos uma aresta no no
    if (this->primeira_aresta != nullptr) {
        //Alocando a nova aresta e mantendo a integridade da lista de arestas
        if (!this->buscaAresta(target_id)) {
            Aresta* aresta = new Aresta(target_id);
            aresta->setPeso(peso);
            this->ultima_aresta->setNextAresta(aresta);
            this->ultima_aresta = aresta;
        }
    }
    else {
        //Alocando a nova aresta e mantendo a integridade da lista de arestas
        this->primeira_aresta = new Aresta(target_id);
        this->primeira_aresta->setPeso(peso);
        this->ultima_aresta = this->primeira_aresta;
    }
}

void No::removerTodasArestas() {
    //Verifica se tem pelo menos uma aresta no No
    if (this->primeira_aresta != nullptr) {

        Aresta* proxima = nullptr;
        Aresta* aux = this->primeira_aresta;
        //Removendo todas as arestas do no
        while (aux != nullptr)
        {
            proxima = aux->getProxAresta();
            delete aux;
        }
    }

    this->primeira_aresta = this->ultima_aresta = nullptr;
}

int No::removerAresta(int id, bool directed, No* target_no) {
    //Verifica se a aresta que ira remover esta no no
    if (this->buscaAresta(id)) {
        Aresta* aux = this->primeira_aresta;
        Aresta* anterior = nullptr;
        //Procurando a aresta para remover
        while (aux->getTargetId()!= id)
        {
            anterior = aux;
            aux = aux->getProxAresta();
        }
        //Mantendo a integridade da lista de arestas
        if (anterior != nullptr)
            anterior->setNextAresta(aux->getProxAresta());
        else
            this->primeira_aresta = aux->getProxAresta();

        if (aux == this->ultima_aresta)
            this->ultima_aresta = anterior;

        if (aux->getProxAresta() == this->ultima_aresta)
            this->ultima_aresta = aux->getProxAresta();
        aux = nullptr;
        delete aux;

        //Verifica se o grafo é direcionado
        if (directed)
            this->decrementOutDegree();
            //diminuir o grau de entrada do proximo no?
        else {
            this->decrementInDegree();
            target_no->decrementInDegree();
        }

        return 1;

    }

    return 0;
}

bool No::buscaAresta(int target_id) {
    //Verifica se tem ao menos uma aresta no no
    if (this->primeira_aresta != nullptr) {
        //procurando pela aresta especifica que é igual ao id passado
        for (Aresta* aux = this->primeira_aresta; aux != nullptr; aux = aux->getProxAresta())
        {
            if (aux->getTargetId() == target_id)
                return true;
        }
    }

    return false;
}

void No::incrementInDegree() {

    this->in_degree++;

}

void No::incrementOutDegree() {

    this->out_degree++;

}

void No::decrementInDegree() {

    this->in_degree--;

}

void No::decrementOutDegree() {

    this->out_degree--;

}

Aresta* No::temArestaEntre(int target_id)
{
    for (Aresta* auxAresta = this->primeira_aresta; auxAresta != nullptr; auxAresta->getProxAresta())
    {
        if (auxAresta->getTargetId() == target_id)
            return auxAresta;
    }

    return nullptr;

}