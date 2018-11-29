//
// Created by andre on 10/09/2018.
//

#include "Vertice.h"

Vertice::Vertice() = default;

Vertice::Vertice(int id) {
    this->id = id;
    this->grau = 0;
    this->bipartidoFlag = 0;
    this->distancia = std::numeric_limits<int>::max();
}

Vertice::Vertice(int id, int peso) {
    this->id = id;
    this->peso = peso;
    this->grau = 0;
    this->bipartidoFlag = 0;
    this->distancia = std::numeric_limits<int>::max();
}

void Vertice::imprimirAdjacentes() {
    for (auto vertice : this->verticesAdjacentes) {
        std::cout << vertice->id << " ";
    }

    std::cout << std::endl;
}