#include <iostream>
#include <string>

#include "Componentes/Grafo/Grafo.h"
#include "Componentes/LeitorArquivo/LeitorArquivo.h"
#include "Componentes/Menu/Menu.h"
#include "Algoritmos/AlgoritmoKruskal.h"
#include "Algoritmos/AlgoritmoPrim.h"

using namespace std;

int main() {
    string caminhoArquivo;
    auto *grafo = new Grafo();


    cout << "TRABALHO PRATICO DCC059 - GRUPO 1" << endl << endl;
    cout << "Digite o caminho do arquivo de dados:" << endl;
    cin >> caminhoArquivo;

    LeitorArquivo::lerArquivo(caminhoArquivo, *grafo);

    // instância para testar algoritmos de arvore geradora minima
    /*grafo->incluirAresta(0, 1, 10);
    grafo->incluirAresta(0, 2, 20);
    grafo->incluirAresta(1, 4, 10);
    grafo->incluirAresta(1, 3, 50);
    grafo->incluirAresta(2, 4, 33);
    grafo->incluirAresta(2, 3, 20);
    grafo->incluirAresta(4, 3, 20);
    grafo->incluirAresta(4, 5, 1);
    grafo->incluirAresta(3, 5, 2);*/

    //AlgoritmoKruskal::encontrarArvoreGeradoraMinima(grafo);
    //AlgoritmoPrim::encontrarArvoreGeradoraMinima(grafo);

    Menu::exibirOpcoes();
    Menu::selecionarOpcao(*grafo);
}