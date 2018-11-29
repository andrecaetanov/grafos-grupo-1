#include <iostream>
#include <string>

#include "Componentes/Grafo/Grafo.h"
#include "Componentes/LeitorArquivo/LeitorArquivo.h"
#include "Componentes/Menu/Menu.h"
#include "Algoritmos/AlgoritmoKruskal.h"
#include "Algoritmos/AlgoritmoPrim.h"
#include "Algoritmos/ArvoreSteinerColetaPremios.h"

using namespace std;

int main() {
    string caminhoArquivo;
    auto *grafo = new Grafo();


    cout << "TRABALHO PRATICO DCC059 - GRUPO 1" << endl << endl;
    //cout << "Digite o caminho do arquivo de dados:" << endl;
    //cin >> caminhoArquivo;

    //LeitorArquivo::lerArquivo(caminhoArquivo, *grafo);

    // instância para testar algoritmos de arvore geradora minima
    /*grafo->incluirAresta(0, 1, 10);
    grafo->incluirAresta(0, 2, 20);
    grafo->incluirAresta(1, 4, 10);
    grafo->incluirAresta(1, 3, 50);
    grafo->incluirAresta(2, 4, 33);
    grafo->incluirAresta(2, 3, 20);
    grafo->incluirAresta(4, 3, 1);
    grafo->incluirAresta(4, 5, 1);
    grafo->incluirAresta(3, 5, 2);*/

    //AlgoritmoKruskal::encontrarArvoreGeradoraMinima(grafo);
    //AlgoritmoPrim::encontrarArvoreGeradoraMinima(grafo);

    // instância para testar algoritmos para o problema ASCP
    auto *vertice0 = new Vertice(0, 10);
    auto *vertice1 = new Vertice(1, 0);
    auto *vertice2 = new Vertice(2, 0);
    auto *vertice3 = new Vertice(3, 150);
    auto *vertice4 = new Vertice(4, 0);
    auto *vertice5 = new Vertice(5, 200);
    auto *vertice6 = new Vertice(6, 0);
    auto *vertice7 = new Vertice(7, 100);
    auto *vertice8 = new Vertice(8, 0);
    auto *vertice9 = new Vertice(9, 20);

    grafo->vertices.push_back(vertice0);
    grafo->vertices.push_back(vertice1);
    grafo->vertices.push_back(vertice2);
    grafo->vertices.push_back(vertice3);
    grafo->vertices.push_back(vertice4);
    grafo->vertices.push_back(vertice5);
    grafo->vertices.push_back(vertice6);
    grafo->vertices.push_back(vertice7);
    grafo->vertices.push_back(vertice8);
    grafo->vertices.push_back(vertice9);

    grafo->arestas.push_back(new Aresta(vertice0, vertice1, 1));
    grafo->arestas.push_back(new Aresta(vertice0, vertice2, 10));
    grafo->arestas.push_back(new Aresta(vertice2, vertice3, 10));
    grafo->arestas.push_back(new Aresta(vertice1, vertice4, 10));
    grafo->arestas.push_back(new Aresta(vertice2, vertice5, 1));
    grafo->arestas.push_back(new Aresta(vertice3, vertice6, 10));
    grafo->arestas.push_back(new Aresta(vertice4, vertice5, 1));
    grafo->arestas.push_back(new Aresta(vertice5, vertice6, 1));
    grafo->arestas.push_back(new Aresta(vertice4, vertice7, 10));
    grafo->arestas.push_back(new Aresta(vertice5, vertice7, 10));
    grafo->arestas.push_back(new Aresta(vertice5, vertice8, 10));
    grafo->arestas.push_back(new Aresta(vertice6, vertice9, 100));
    grafo->arestas.push_back(new Aresta(vertice8, vertice9, 100));

    //ArvoreSteinerColetaPremios::algoritmoGuloso(grafo);
    ArvoreSteinerColetaPremios::algoritmoGulosoRandomizado(grafo, 50, 20);

    //Menu::exibirOpcoes();
    //Menu::selecionarOpcao(*grafo);
}