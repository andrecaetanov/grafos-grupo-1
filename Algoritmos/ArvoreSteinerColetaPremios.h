//
// Created by andre on 17/11/2018.
//

#ifndef GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H
#define GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H

#include <cstdlib>
#include <map>
#include <math.h>

#include "../Componentes/Grafo/Grafo.h"

class ArvoreSteinerColetaPremios {
public:
    struct Alfa {
        int indice;
        float valor;
        double probabilidade;
        int numVezesSelecionado;
        int somaCustosSolucoes;
        double mediaCustosSolucoes;
    };

    static void algoritmoGuloso(Grafo *grafo);
    static void algoritmoGulosoRandomizado(Grafo *grafo, float alfa, int numIteracoes);
    static void algoritmoGulosoRandomizadoReativo(Grafo *grafo, int numBlocos, int iteracoesBloco, int sigma);
    static void calcularBeneficioVertices(Grafo *grafo);
    static Grafo *obterSolucaoRandomizado(Grafo *grafo, int posicaoMaximaVertice);
    static Grafo *obterSolucao(Grafo *grafo, Vertice *verticeInicial);
    static void calcularCustoSolucao(Grafo *grafo, Grafo *solucao);
    static void incluirVerticeSolucao(Grafo *solucao);
    static void imprimirSolucao(Grafo *solucao);
    static Alfa escolherAlfaAleatorio(Alfa *alfas);
    static void atualizarProbabilidadesAlfas(Alfa *alfas, int custoMelhorSolucao, int sigma);
};


#endif //GRAFOS_GRUPO_1_ARVORESTEINERCOLETAPREMIOS_H
