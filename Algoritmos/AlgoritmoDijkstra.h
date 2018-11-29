//
// Created by andre on 25/11/2018.
//

#ifndef GRAFOS_GRUPO_1_ALGORITMODIJKSTRA_H
#define GRAFOS_GRUPO_1_ALGORITMODIJKSTRA_H


#include "../Componentes/Grafo/Vertice.h"
#include "../Componentes/Grafo/Grafo.h"

using namespace std;

class AlgoritmoDijkstra {
public:
    static void apresentarCustoCaminhoMinimo(Grafo *grafo, int idVertice1, int idVertice2);
    static Vertice *encontrarVerticeDistanciaMinima(list<Vertice *> vertices);
};


#endif //GRAFOS_GRUPO_1_ALGORITMODIJKSTRA_H
