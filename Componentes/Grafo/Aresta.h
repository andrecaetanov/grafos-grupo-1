//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_ARESTA_H
#define GRAFOS_GRUPO_1_ARESTA_H

class Vertice;

class Aresta {
public:
    Vertice *vertice1;
    Vertice *vertice2;
    int peso;

    Aresta();
    explicit Aresta(Vertice *vertice1, Vertice *vertice2);
    Aresta(Vertice *vertice1, Vertice *vertice2, int peso);
    ~Aresta() = default;
};


#endif //GRAFOS_GRUPO_1_ARESTA_H
