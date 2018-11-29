//
// Created by andre on 25/11/2018.
//

#include "AlgoritmoDijkstra.h"

void AlgoritmoDijkstra::apresentarCustoCaminhoMinimo(Grafo *grafo, int idVertice1, int idVertice2) {
    Vertice *verticeInicial = grafo->getVertice(idVertice1);
    verticeInicial->distancia = 0;

    list<Vertice *> vertices(grafo->vertices);

    while (!vertices.empty()) {
        Vertice *vertice = encontrarVerticeDistanciaMinima(vertices);

        for (auto verticeAdjacente : vertice->verticesAdjacentes) {
            Aresta *aresta = grafo->getAresta(idVertice1, idVertice2);

            if (verticeAdjacente->distancia > vertice->distancia + aresta->peso) {
                verticeAdjacente->distancia = vertice->distancia + aresta->peso;
                grafo->getVertice(verticeAdjacente->id)->distancia = verticeAdjacente->distancia;
            }
        }

        vertices.remove(vertice);
    }

    int custo = grafo->getVertice(idVertice2)->distancia;

    if (custo < numeric_limits<int>::max()) {
        cout << "O custo do caminho mínimo é: " << grafo->getVertice(idVertice2)->distancia << endl;
    } else {
        cout << "Não existe caminho entre os dois vértices." << endl;
    }
}

Vertice *AlgoritmoDijkstra::encontrarVerticeDistanciaMinima(list<Vertice *> vertices) {
    Vertice *verticeDistanciaMinima = vertices.front();

    for (auto i = vertices.begin(); i != vertices.end(); i++) {
        Vertice *vertice = *i;
        if (vertice->distancia < verticeDistanciaMinima->distancia) {
            verticeDistanciaMinima = vertice;
        }
    }

    return verticeDistanciaMinima;
}
