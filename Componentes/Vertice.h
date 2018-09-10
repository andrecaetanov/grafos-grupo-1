//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_VERTICE_H
#define GRAFOS_GRUPO_1_VERTICE_H

#include <list>

class Vertice {
public:
    int id;
    int grau;
    double peso;
    std::list<Vertice *> verticesAdjacentes;

    Vertice(int id, double peso);
    Vertice(double peso);
    ~Vertice() = default;
};


#endif //GRAFOS_GRUPO_1_VERTICE_H
