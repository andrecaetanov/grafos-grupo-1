//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_GRAFO_H
#define GRAFOS_GRUPO_1_GRAFO_H

#include <list>
#include "Vertice.h"
#include "Aresta.h"

class Grafo {
public:
    int ordem;
    std::list<Vertice *> vertices;
    std::list<Aresta *> arestas;

    Grafo();
    ~Grafo() = default;
};


#endif //GRAFOS_GRUPO_1_GRAFO_H
