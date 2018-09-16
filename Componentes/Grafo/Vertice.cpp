//
// Created by andre on 10/09/2018.
//

#include "Vertice.h"

Vertice::Vertice(int id) {
    this->id = id;
    this->grau = 0;
    this->bipartidoFlag = 0;
}

Vertice::Vertice(int id, int peso) {
    this->id = id;
    this->peso = peso;
    this->grau = 0;
    this->bipartidoFlag = 0;
}

void Vertice::imprimirAdjacentes() {
    for (auto i = this->arestas.begin(); i != this->arestas.end(); i++) {
        Aresta *aresta = *i;

        std::cout << aresta->verticeAdjacente->id << " ";
    }

    std::cout << std::endl;
}
