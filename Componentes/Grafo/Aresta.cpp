//
// Created by andre on 10/09/2018.
//

#include "Aresta.h"

Aresta::Aresta() = default;

Aresta::Aresta(Vertice *vertice1, Vertice *vertice2) {
    vertice1->arestas.push_back(this);
    vertice2->arestas.push_back(this);

    vertice1->verticesAdjacentes.push_back(vertice2);
    vertice1->grau++;

    vertice2->verticesAdjacentes.push_back(vertice1);
    vertice2->grau++;

    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
}

Aresta::Aresta(Vertice *vertice1, Vertice *vertice2, int peso) {
    vertice1->arestas.push_back(this);
    vertice2->arestas.push_back(this);

    vertice1->verticesAdjacentes.push_back(vertice2);
    vertice1->grau++;

    vertice2->verticesAdjacentes.push_back(vertice1);
    vertice2->grau++;

    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
    this->peso = peso;
}
