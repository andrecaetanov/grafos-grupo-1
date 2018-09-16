//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_ARESTA_H
#define GRAFOS_GRUPO_1_ARESTA_H

class Vertice;

class Aresta {
public:
    Vertice *verticeAdjacente;
    int peso;

    Aresta(Vertice *verticeAdjacente);
    Aresta(Vertice *verticeAdjacente, int peso);
    ~Aresta() = default;
};


#endif //GRAFOS_GRUPO_1_ARESTA_H
