//
// Created by andre on 10/09/2018.
//

#include "Aresta.h"

Aresta::Aresta(Vertice *vertice1, Vertice *vertice2) {
    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
}

Aresta::Aresta(Vertice *vertice1, Vertice *vertice2, int peso) {
    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
    this->peso = peso;
}
