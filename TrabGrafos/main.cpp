#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include "Grafo.h"
#include "No.h"

using namespace std;

Grafo* leitura(ifstream& input_file, int direcionado, int arestaComPeso, int noComPeso) {
    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNoSource;
    int idNoTarget;
    int ordem;

    //Pegando a ordem do grafo
    input_file >> ordem;

    //Criando o Grafo
    Grafo* grafo = new Grafo(ordem, direcionado, arestaComPeso, noComPeso);

    //Leitura do arquivo

    
    if (!grafo->getArestaComPeso() && !grafo->getNoComPeso()) {
        //Nem aresta nem no com peso
        while (input_file >> idNoSource >> idNoTarget)
        {
            grafo->inserirAresta(idNoSource, idNoTarget, 0);
        }
    }
    else if (grafo->getArestaComPeso() && !grafo->getNoComPeso()) {
        //Apenas aresta com peso
        float pesoAresta;
        while (input_file >> idNoSource >> idNoTarget >> pesoAresta)
        {
            grafo->inserirAresta(idNoSource, idNoTarget, pesoAresta);
        }
    }
    else if (!grafo->getArestaComPeso() && grafo->getNoComPeso()) {
        //Apenas no com peso
        float noSourcePeso, noTargetPeso;
        while (input_file >> idNoSource >> noSourcePeso >> idNoTarget >> noTargetPeso)
        {
            grafo->inserirAresta(idNoSource, idNoTarget, 0);
            grafo->getNo(idNoSource)->setPeso(noSourcePeso);
            grafo->getNo(idNoTarget)->setPeso(noTargetPeso);
        }
    }
    else if (grafo->getArestaComPeso() && grafo->getNoComPeso()) {
        //ambos com peso
        float noSourcePeso, noTargetPeso, pesoAresta;
        while (input_file >> idNoSource >> noSourcePeso >> idNoTarget >> noTargetPeso >> pesoAresta)
        {
            grafo->inserirAresta(idNoSource, idNoTarget, pesoAresta);
            grafo->getNo(idNoSource)->setPeso(noSourcePeso);
            grafo->getNo(idNoTarget)->setPeso(noTargetPeso);
        }
    }

    return grafo;

}

Grafo* leituraInstancia(ifstream& input_file, int direcionado, int arestaComPeso, int noComPeso) {
    
    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNoSource;
    int idNoTarget;
    int ordem;
    int numArestas;

    //Pegando a ordem 
    input_file >> ordem >> numArestas;

    //Criando o objeto grafo
    Grafo* grafo = new Grafo(ordem, direcionado, arestaComPeso, noComPeso);

    //Leitura de arquivo
    while (input_file >> idNoSource >> idNoTarget) {
        grafo->inserirAresta(idNoSource, idNoTarget, 0);
    }

    return grafo;

}

int menu() {

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Subgrafo induzido por conjunto de vértices" << endl;
    cout << "[2] Caminho Mínimo entre dois vértices - Dijkstra" << endl;
    cout << "[3] Caminho Mínimo entre dois vértices - Floyd" << endl;
    cout << "[4] Árvore Geradora Mínima de Prim" << endl;
    cout << "[5] Árvore Geradora Mínima de Kruskal" << endl;
    cout << "[6] Imprimir caminhamento em largura" << endl;
    cout << "[7] Imprimir ordenacao topológica" << endl;
    cout << "[8] Algoritmo Guloso" << endl;
    cout << "[9] Algoritmo Guloso Randomizado " << endl;
    cout << "[10] Algoritmo Guloso Randomizado Reativo" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    return selecao;

}

void selecionar(int selecao, Grafo* grafo, ofstream& output_file) {
    switch (selecao) {

        //Subgrafo induzido por um conjunto de vértices X;
    case 1: {

        break;
    }
          //Caminho mínimo entre dois vértices usando Dijkstra;
    case 2: {

        break;
    }

          //Caminho mínimo entre dois vértices usando Floyd;
    case 3: {

        break;
    }

          //AGM - Kruscal;
    case 4: {



        break;
    }

          //AGM Prim;
    case 5: {

        break;
    }

          //Busca em largura;
    case 6: {

        break;
    }
          //Ordenação Topologica;
    case 7: {


        break;
    }
    default:
    {
        cout << " Error!!! invalid option!!" << endl;
    }

    }
}

int mainMenu(ofstream& output_file, Grafo* grafo) {

    int selecao = 1;

    while (selecao != 0) {
        system("clear");
        selecao = menu();

        if (output_file.is_open())
            selecionar(selecao, grafo, output_file);

        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;

    }

    return 0;
}


//main para testes
int main()
{
    cout << "hello world!" << endl;
    Grafo* grafo = new Grafo(9,1,0,0);
   
    grafo->inserirAresta(0, 1, 2);//
    grafo->inserirAresta(0, 2, 4);//
    grafo->inserirAresta(1, 2, 1);//
    grafo->inserirAresta(1, 7, 4);//
    grafo->inserirAresta(1, 4, 5);//
    grafo->inserirAresta(2, 1, 5);//
    grafo->inserirAresta(2, 7, 2);//
    grafo->inserirAresta(2, 4, 3);//
    grafo->inserirAresta(7, 4, 1);//
    /*
    grafo->inserirNo(1);
    grafo->inserirNo(2);
    grafo->inserirNo(3);
    grafo->inserirNo(4);
    grafo->inserirNo(5);
    grafo->inserirNo(6);
    grafo->inserirNo(7);

    grafo->inserirAresta(1, 2, 0);
    grafo->inserirAresta(2, 4, 0);
    grafo->inserirAresta(4, 7, 0);
    grafo->inserirAresta(2, 3, 0);
    grafo->inserirAresta(5, 6, 0);*/

    

    grafo->printGrafo();
    cout << endl;
    grafo->dijkstra(7, 2);

    cout << endl << endl;
    
}

//Mudar o nome dessa mainPrincipal para somente main qundo for executar o programa sem ser para testes
int mainPrincipal(int argc, char const* argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 6) {

        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;

    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    string instance;
    if (input_file_name.find("v") <= input_file_name.size()) {
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " with instance " << instance << " ... " << endl;
    }

    //Abrindo arquivo de entrada
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);



    Grafo* grafo;

    if (input_file.is_open()) {

        grafo = leituraInstancia(input_file, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
        mainMenu(output_file, grafo);
    }
    else
        cout << "Unable to open " << argv[1];


    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saída
    output_file.close();

    return 0;
}


