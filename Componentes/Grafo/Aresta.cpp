//
// Created by andre on 10/09/2018.
//

#include "Aresta.h"

Aresta::Aresta(Vertice *verticeAdjacente) {
    this->verticeAdjacente = verticeAdjacente;
}

Aresta::Aresta(Vertice *verticeAdjacente, int peso) {
    this->verticeAdjacente = verticeAdjacente;
    this->peso = peso;
}
