//
// Created by andre on 17/11/2018.
//

#ifndef GRAFOS_GRUPO_1_ALGORITMOPRIM_H
#define GRAFOS_GRUPO_1_ALGORITMOPRIM_H

#include <limits>

#include "../Componentes/Grafo/Grafo.h"

using namespace std;

class AlgoritmoPrim {
public:
    static void encontrarArvoreGeradoraMinima(Grafo *grafo);
    static Aresta *obterArestaMenorPeso(Grafo *grafo, Grafo *arvoreGeradoraMinima);
    static void imprimirSolucao(Grafo *grafo);
};


#endif //GRAFOS_GRUPO_1_ALGORITMOPRIM_H
