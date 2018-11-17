//
// Created by andre on 16/11/2018.
//

#include "AlgoritmoKruskal.h"

void AlgoritmoKruskal::encontrarArvoreGeradoraMinima(Grafo *grafo) {
    if (grafo->ehConexo()) {
        auto *arvoreGeradoraMinima = new Grafo;
        list<Aresta *> arestas(grafo->arestas); // cria uma cópia da lista de arestas do grafo

        // ordena a lista de arestas por peso em ordem crescente
        arestas.sort([](Aresta *aresta1, Aresta *aresta2) {
            return aresta1->peso < aresta2->peso;
        });

        for (auto i = arestas.begin(); arvoreGeradoraMinima->arestas.size() < grafo->vertices.size() - 1; i++) {
            Aresta *aresta = *i;
            auto *vertice1 = new Vertice(aresta->vertice1->id);
            auto *vertice2 = new Vertice(aresta->vertice2->id);

            if (!arestaFormaCiclo(vertice1, vertice2)) {
                auto *novaAresta = new Aresta(vertice1, vertice2, aresta->peso);

                if (!arvoreGeradoraMinima->possuiVertice(vertice1->id)) {
                    arvoreGeradoraMinima->vertices.push_back(vertice1);
                }

                if (!arvoreGeradoraMinima->possuiVertice(vertice2->id)) {
                    arvoreGeradoraMinima->vertices.push_back(vertice2);
                }

                arvoreGeradoraMinima->arestas.push_back(novaAresta);
                vertice1->verticesAdjacentes.push_back(vertice2);
                vertice2->verticesAdjacentes.push_back(vertice1);
            }
        }

        imprimirSolucao(arvoreGeradoraMinima);
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}

bool AlgoritmoKruskal::arestaFormaCiclo(Vertice *vertice1, Vertice *vertice2) {
    for (auto verticeAdjacente : vertice1->verticesAdjacentes) {
        for (auto verticeAdjacenteAoAdjacente : verticeAdjacente->verticesAdjacentes) {
            if (verticeAdjacenteAoAdjacente->id == vertice2->id) {
                return true;
            }
        }
    }

    return false;
}

void AlgoritmoKruskal::imprimirSolucao(Grafo *grafo) {
    cout << "Arvore Geradora Minima - Kruskal:" << endl;
    for (auto aresta : grafo->arestas) {
        cout << "(" << aresta->vertice1->id << "," << aresta->vertice2->id << ") ";
    }
    cout << endl;
}
