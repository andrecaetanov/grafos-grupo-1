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
    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;

        if (vertice->id == id) {
            return vertice->grau;
        }
    }

    return -1;
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

void Grafo::imprimirVizinhancaAberta(int id) {
    if (possuiVertice(id)) {
        for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
            Vertice *vertice = *i;

            if (vertice->id == id) {
                cout << "Vizinhança aberta do Vértice " << vertice->id << ": ";
                vertice->imprimirAdjacentes();
            }
        }
    } else {
        cout << "Vértice não existe no grafo." << endl;
    }
}

void Grafo::imprimirVizinhancaFechada(int id) {
    if (possuiVertice(id)) {
        for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
            Vertice *vertice = *i;

            if (vertice->id == id) {
                cout << "Vizinhança aberta do Vértice " << vertice->id << ": " << vertice->id << " ";
                vertice->imprimirAdjacentes();
            }
        }
    } else {
        cout << "Vértice não existe no grafo." << endl;
    }
}

bool Grafo::verificarGrafoCompleto() {
    for (auto i = this->sequenciaGraus.begin(); i != this->sequenciaGraus.end(); i++) {
        int grau = *i;

        if (grau != this->ordem - 1) {
            return false;
        }
    }

    return true;
}

bool Grafo::verificarGrafoBipartido() {
    const int FLAG_SEM_PARTICAO = 0;
    const int FLAG_PRIMEIRA_PARTICAO = 1;
    const int FLAG_SEGUNDA_PARTICAO = 2;

    for (auto i = this->vertices.begin(); i != this->vertices.end(); i++) {
        Vertice *vertice = *i;
        int flagVertice = vertice->bipartidoFlag;

        if(flagVertice == FLAG_SEM_PARTICAO) {
            flagVertice = FLAG_PRIMEIRA_PARTICAO;
        }

        for (auto j = vertice->arestas.begin(); j != vertice->arestas.end(); j++) {
            Aresta *aresta = *j;
            int flagVerticeAdjacente = aresta->verticeAdjacente->bipartidoFlag;

            if (flagVerticeAdjacente == FLAG_SEM_PARTICAO) {
                if (flagVertice == FLAG_PRIMEIRA_PARTICAO ) {
                    flagVerticeAdjacente = FLAG_SEGUNDA_PARTICAO;
                } else {
                    flagVerticeAdjacente = FLAG_PRIMEIRA_PARTICAO ;
                }
            } else if (flagVerticeAdjacente == flagVertice) {
                return false;
            }
        }
    }

    return true;
}

void Grafo::imprimirSequenciaGraus() {
    cout << "Sequência de graus do grafo: ";

    for (auto i = this->sequenciaGraus.begin(); i != this->sequenciaGraus.end(); i++) {
        int grau = *i;

        cout << grau << " ";
    }

    cout << endl;
}
