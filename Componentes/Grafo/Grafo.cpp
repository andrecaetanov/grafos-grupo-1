//
// Created by andre on 10/09/2018.
//

#include "Grafo.h"
#include "Aresta.h"

Grafo::Grafo() {
    this->ordem = 0;
}

void Grafo::atualizarSequenciaGraus() {
    this->sequenciaGraus.clear();

    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;
        int grau = vertice->grau;

        this->sequenciaGraus.push_back(grau);
    }

    this->sequenciaGraus.sort();
    this->sequenciaGraus.reverse();
}

bool Grafo::possuiVertice(int id) {
    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;

        if (vertice->id == id) {
            return true;
        }
    }

    return false;
}

void Grafo::incluirVertice(int id) {
    if (!possuiVertice(id)) {
        Vertice *vertice = new Vertice(id);
        this->vertices.push_back(vertice);

        this->ordem++;
        atualizarSequenciaGraus();
    } else {
        cout << "Vértice já existe no grafo." << endl;
    }
}

void Grafo::excluirVertice(int id) {
    if (possuiVertice(id)) {
        for (auto i = this->vertices.begin(); i != this->vertices.end();) {
            Vertice *vertice = *i;

            if (vertice->id == id) {
                this->vertices.erase(i);
            } else {
                for (auto j = vertice->arestas.begin(); j != vertice->arestas.end(); j++) {
                    Aresta *aresta = *j;

                    if (aresta->verticeAdjacente->id == id) {
                        vertice->arestas.erase(j);
                    }
                }

                i++;
            }
        }

        this->ordem--;
        atualizarSequenciaGraus();
    } else {
        cout << "Vértice não existe no grafo." << endl;
    }
}

Vertice* Grafo::getVertice(int id) {
    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;

        if (vertice->id == id) {
            return vertice;
        }
    }

    return nullptr;
}

int Grafo::retornarGrauVertice(int id) {
    int grau = NULL;

    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;

        if (vertice->id == id) {
            grau = vertice->grau;
        }
    }

    return grau;
}

bool Grafo::verificarKRegularidade(int k) {
    for (auto i = this->sequenciaGraus.begin(); i != this->sequenciaGraus.end(); i++) {
        int grau = *i;

        if (grau != k) {
            return false;
        }
    }

    return true;
}
