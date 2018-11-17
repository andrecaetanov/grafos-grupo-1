//
// Created by andre on 17/11/2018.
//

#include "AlgoritmoPrim.h"

void AlgoritmoPrim::encontrarArvoreGeradoraMinima(Grafo *grafo) {
    if (grafo->ehConexo()) {
        auto *arvoreGeradoraMinima = new Grafo();

        auto *verticeInicial = new Vertice(grafo->vertices.front()->id);
        arvoreGeradoraMinima->vertices.push_back(verticeInicial);

        while (arvoreGeradoraMinima->vertices.size() < grafo->vertices.size()) {
            Aresta *aresta = obterArestaMenorPeso(grafo, arvoreGeradoraMinima);

            auto *vertice1 = new Vertice(aresta->vertice1->id);
            auto *vertice2 = new Vertice(aresta->vertice2->id);

            if (!arvoreGeradoraMinima->possuiVertice(vertice1->id)) {
                arvoreGeradoraMinima->vertices.push_back(vertice1);
            }

            if (!arvoreGeradoraMinima->possuiVertice(vertice2->id)) {
                arvoreGeradoraMinima->vertices.push_back(vertice2);
            }

            arvoreGeradoraMinima->arestas.push_back(aresta);
            vertice1->verticesAdjacentes.push_back(vertice2);
            vertice2->verticesAdjacentes.push_back(vertice1);
        }

        imprimirSolucao(arvoreGeradoraMinima);
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}

Aresta *AlgoritmoPrim::obterArestaMenorPeso(Grafo *grafo, Grafo *arvoreGeradoraMinima) {
    auto *arestaMenorPeso = new Aresta();
    int pesoMinimo = numeric_limits<int>::max();

    for (auto aresta : grafo->arestas) {
        if (!(arvoreGeradoraMinima->possuiVertice(aresta->vertice1->id)
            && arvoreGeradoraMinima->possuiVertice(aresta->vertice2->id))) {
            if (arvoreGeradoraMinima->possuiVertice(aresta->vertice1->id)
                || arvoreGeradoraMinima->possuiVertice(aresta->vertice2->id)) {
                if (aresta->peso < pesoMinimo) {
                    arestaMenorPeso = aresta;
                    pesoMinimo = aresta->peso;
                }
            }
        }
    }

    return arestaMenorPeso;
}

void AlgoritmoPrim::imprimirSolucao(Grafo *grafo) {
    cout << "Arvore Geradora Minima - Prim:" << endl;
    for (auto aresta : grafo->arestas) {
        cout << "(" << aresta->vertice1->id << "," << aresta->vertice2->id << ") ";
    }
    cout << endl;
}
