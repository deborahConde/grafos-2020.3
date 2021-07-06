#include "Graph.h"
#include "Node.h"
#include "Edge.h"
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

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{

    return this->order;
}

int Graph::getNumberEdges()
{

    return this->number_edges;
}
//Function that verifies if the graph is directed
bool Graph::getDirected()
{

    return this->directed;
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()
{

    return this->weighted_node;
}


Node *Graph::getFirstNode()
{

    return this->first_node;
}

Node *Graph::getLastNode()
{

    return this->last_node;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id) {
    Node* next;
	Node* aux = nullptr;
	if (this->first_node == nullptr) {
		this->first_node = new Node(id);
	}
	else {
		next = this->first_node;
		while (next != nullptr)
		{
			aux = next;
			next = next->getNextNode();
		}
		aux->setNextNode(new Node(id));
	}
}

void Graph::insertEdge(int id, int target_id, float weight) {
    Node* node = this->first_node;

    if(node != nullptr) {
        while (node->getId() != id) {
            node = node->getNextNode();
        }
	} else {
        insertNode(id);
    }

	node->insertEdge(target_id, weight);
	this->number_edges++;
    
}

void Graph::removeNode(int id) { 
    Node* no;
	Node* noAux = new Node(id);
	Node* anterior;

	for (no = this->first_node; no != nullptr; no = no->getNextNode())
	{
		no->removeEdge(id, 0, noAux);
	}

	no = this->first_node;

	//se o no a ser excluido for o primeiro na lista
	if (no->getId() == id) {
		this->first_node = no->getNextNode();
		no->removeAllEdges();
		delete no;
		return;
	}
	//anterior recebe o primeiro
	anterior = no;
	for (no = no->getNextNode(); no != nullptr; no = no->getNextNode())
	{	
		//no = o proximo depois do anterior
		if (no->getId() == id) {
			anterior->setNextNode(no->getNextNode());
			no->removeAllEdges();
			delete no;
			return;
		}
		//anterior = no atual antes da proxima iteracao
		anterior = no;
	}
}

bool Graph::searchNode(int id)
{
    
}

Node *Graph::getNode(int id)
{

    
}


//Function that prints a set of edges belongs breadth tree

void Graph::breadthFirstSearch(ofstream &output_file){
    
}



float Graph::floydMarshall(int idSource, int idTarget){
    
}

   

float Graph::dijkstra(int idSource, int idTarget){
    
}

//function that prints a topological sorting
void topologicalSorting(){

}

void breadthFirstSearch(ofstream& output_file){

}
Graph* getVertexInduced(int* listIdNodes){

}

Graph* agmKuskal(){

}
Graph* agmPrim(){

}
