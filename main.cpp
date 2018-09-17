#include <iostream>
#include <string>

#include "Componentes/Grafo/Grafo.h"
#include "Componentes/LeitorArquivo/LeitorArquivo.h"
#include "Componentes/Menu/Menu.h"

using namespace std;

int main() {
    string caminhoArquivo;
    auto *grafo = new Grafo();


    cout << "TRABALHO PRATICO DCC059 - GRUPO 1" << endl << endl;
    cout << "Digite o caminho do arquivo de dados:" << endl;

    cin >> caminhoArquivo;
    std::ifstream arquivo(caminhoArquivo);

    LeitorArquivo::lerArquivo(caminhoArquivo, *grafo);

    Menu::exibirOpcoes();
    Menu::selecionarOpcao(*grafo);
}