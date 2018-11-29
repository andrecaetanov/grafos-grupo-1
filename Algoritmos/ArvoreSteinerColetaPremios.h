//
// Created by andre on 17/11/2018.
//

#ifndef GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H
#define GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H

#include <cstdlib>

#include "../Componentes/Grafo/Grafo.h"

class ArvoreSteinerColetaPremios {
public:
    static void algoritmoGuloso(Grafo *grafo);
    static void algoritmoGulosoRandomizado(Grafo *grafo, float alcanceRandom, int numIteracoes);
    static void calcularBeneficioVertices(Grafo *grafo);
    static Grafo *obterSolucao(Grafo *grafo, Vertice *verticeInicial);
    static void calcularCustoSolucao(Grafo *grafo, Grafo *solucao);
    static void incluirVerticeSolucao(Grafo *solucao);
    static void imprimirSolucao(Grafo *solucao);
};


#endif //GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H
