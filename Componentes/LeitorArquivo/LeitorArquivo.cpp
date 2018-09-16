//
// Created by andre on 10/09/2018.
//

#include "LeitorArquivo.h"

void LeitorArquivo::lerArquivo(std::string caminhoArquivo, Grafo &grafo) {
    std::ifstream arquivo(caminhoArquivo);

    if (arquivo.is_open()) {
        atribuirDados(arquivo, grafo);
    } else {
        std::cout << "Erro na leitura do arquivo." << std::endl;
        exit(0);
    }
}

void LeitorArquivo::atribuirDados(std::ifstream &arquivo, Grafo &grafo) {
    int id1;
    int id2;
    int pesoAresta;

    arquivo >> grafo.ordem;

    while (arquivo >> id1 >> id2 >> pesoAresta) {
        Vertice *vertice1;
        Vertice *vertice2;

        if (grafo.possuiVertice(id1)) {
            vertice1 = grafo.getVertice(id1);
        } else {
            vertice1 = new Vertice(id1);
        }

        if (grafo.possuiVertice(id2)) {
            vertice2 = grafo.getVertice(id2);
        } else {
            vertice2 = new Vertice(id2);
        }

        Aresta *aresta1 = new Aresta(vertice2, pesoAresta);
        Aresta *aresta2 = new Aresta(vertice1, pesoAresta);

        vertice1->arestas.push_back(aresta1);
        vertice2->arestas.push_back(aresta2);

        vertice1->grau++;
        vertice2->grau++;
    }
}
