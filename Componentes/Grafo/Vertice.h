//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_VERTICE_H
#define GRAFOS_GRUPO_1_VERTICE_H

#include <list>
#include <iostream>

class Vertice {
public:
    int id;
    int grau;
    int peso;
    std::list<Vertice *> verticesAdjacentes;
    int bipartidoFlag;

    explicit Vertice(int id);
    Vertice(int id, int peso);
    ~Vertice() = default;

    void imprimirAdjacentes();
};


#endif //GRAFOS_GRUPO_1_VERTICE_H
