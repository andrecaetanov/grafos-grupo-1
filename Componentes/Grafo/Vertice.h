//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_VERTICE_H
#define GRAFOS_GRUPO_1_VERTICE_H

#include <list>
#include <iostream>
#include <limits>

class Aresta;

class Vertice {
public:
    int id;
    int grau;
    int peso;
    std::list<Vertice *> verticesAdjacentes;
    std::list<Aresta *> arestas;
    int bipartidoFlag;
    int distancia; // usada no algoritmo de dijkstra
    float beneficio; // benefício associado ao problema de Árvore de Steienr com Coleta de Prêmios

    Vertice();
    explicit Vertice(int id);
    Vertice(int id, int peso);
    ~Vertice() = default;

    void imprimirAdjacentes();
    void calcularBeneficio();
};


#endif //GRAFOS_GRUPO_1_VERTICE_H
