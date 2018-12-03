#include <iostream>
#include <string>

#include "Componentes/Grafo/Grafo.h"
#include "Componentes/LeitorArquivo/LeitorArquivo.h"
#include "Componentes/Menu/Menu.h"
#include "Algoritmos/AlgoritmoKruskal.h"
#include "Algoritmos/AlgoritmoPrim.h"
#include "Algoritmos/ArvoreSteinerColetaPremios.h"

using namespace std;

int main(int argc, char* argv[]) {
    auto *grafo = new Grafo();

    string arquivoEntrada = argv[1];
    string arquivoSaida = argv[2];

    LeitorArquivo::lerArquivo(arquivoEntrada, *grafo);

    Menu::exibirOpcoes();
    Menu::selecionarOpcao(*grafo);
}