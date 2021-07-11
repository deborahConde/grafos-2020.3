#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include "Graph.h"
#include "Node.h"

using namespace std;

Graph* leitura(ifstream& input_file, int directed, int weightedEdge, int weightedNode){

    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode);

    //Leitura de arquivo

    if(!graph->getWeightedEdge() && !graph->getWeightedNode()){

        while(input_file >> idNodeSource >> idNodeTarget) {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);

        }

    }else if(graph->getWeightedEdge() && !graph->getWeightedNode() ){

        float edgeWeight;

        while(input_file >> idNodeSource >> idNodeTarget >> edgeWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);

        }

    }else if(graph->getWeightedNode() && !graph->getWeightedEdge()){

        float nodeSourceWeight, nodeTargetWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, 0);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }

    }else if(graph->getWeightedNode() && graph->getWeightedEdge()){

        float nodeSourceWeight, nodeTargetWeight, edgeWeight;

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) {

            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);
            graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);
            graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);

        }

    }

    return graph;
}

Graph* leituraInstancia(ifstream& input_file, int direcionado, int ponderado, int peso){

    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNodeSource;
    int idNodeTarget;
    int order;
    int valPesoAresta;

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, direcionado, ponderado, peso);

    //Leitura de arquivo

    

    // Para um grafo direcionado
    if ( ponderado == 1) {
        // Para um grafo ponderado (Peso nas arestas)
        while(input_file >> idNodeSource >> idNodeTarget >> valPesoAresta) {
            if (!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
            }
            graph->insertEdge(idNodeSource, idNodeTarget, valPesoAresta);
        }
    } else {
        // Para um grafo simples
        while(input_file >> idNodeSource >> idNodeTarget) {
            if (!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
            }
            graph->insertEdge(idNodeSource, idNodeTarget, 0);
        }
    }
    

    // Para um grafo peso nos vertices

    

    return graph;
}

int menu(){

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Fecho Transitivo Direto" << endl;
    cout << "[2] Fecho Transitivo Indireto" << endl;
    cout << "[3] Caminho Mínimo entre dois vértices - Dijkstra"<< endl;
    cout << "[4] Caminho Mínimo entre dois vértices - Floyd" << endl;
    cout << "[5] Árvore Geradora Mínima de Prim" << endl;
    cout << "[6] Árvore Geradora Mínima de Kruskal" << endl;
    cout << "[7] Imprimir caminhamento em profundidade" << endl;
    cout << "[8] Imprimir ordenacao topológica" << endl;
    cout << "[9] Algoritmo Guloso" << endl;
    cout << "[10] Algoritmo Guloso Randomizado " << endl;
    cout << "[11] Algoritmo Guloso Randomizado Reativo" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    return selecao;

}

void selecionar(int selecao, Graph* graph, ofstream& output_file){

    switch (selecao) {

        //Fecho Transitivo Direto
        case 1:{

            break;
        }
            //Fecho Transitivo Indireto;
        case 2:{

            break;
        }

            //Caminho mínimo entre dois vértices usando djikstra;
        case 3:{

            break;
        }

       // caminho minino usando floyd
        case 4:{

            break;
        }

            //AGM Prim;
        case 5:{

            break;
        }

            //AGM - Kruscal;
        case 6:{

            break;
        }
            //Caminhamento Profundidade
        case 7:{
            break;
        }
            //Ordenação Topologica;
        case 8:{


            break;
        }
        default:
        {
            cout << " Error!!! invalid option!!" << endl;
        }

    }
}

int mainMenu(ofstream& output_file, Graph* graph){

    int selecao = 1;

    while(selecao != 0){
        system("clear");
        selecao = menu();

        if(output_file.is_open())
            selecionar(selecao, graph, output_file);

        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;

    }

    return 0;
}



int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 6) {

        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;

    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    int direcionado = atoi(argv[3]);
    int ponderado = atoi(argv[4]);
    int peso = atoi(argv[5]);

    string instance;
    if(input_file_name.find("v") <= input_file_name.size()){
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " with instance " << instance << " ... " << endl;
    }

    //Abrindo arquivo de entrada
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);



    Graph* graph;

    if(input_file.is_open()){

        graph = leituraInstancia(input_file, direcionado, ponderado, peso);

    }else
        cout << "Unable to open " << argv[1];


    //mainMenu(output_file, graph);
    graph->printGrafoDot(output_file);

    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saída
    output_file.close();

    return 0;
}

