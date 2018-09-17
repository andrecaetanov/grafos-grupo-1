//
// Created by andre on 10/09/2018.
//

#include "Grafo.h"

Grafo::Grafo() {
    this->ordem = 0;
}

void Grafo::atualizarSequenciaGraus() {
    this->sequenciaGraus.clear();

    for (auto vertice : this->vertices) {
        int grau = vertice->grau;

        this->sequenciaGraus.push_back(grau);
    }

    this->sequenciaGraus.sort();
    this->sequenciaGraus.reverse();
}

bool Grafo::possuiVertice(int id) {
    for (auto vertice : this->vertices) {
        if (vertice->id == id) {
            return true;
        }
    }

    return false;
}

void Grafo::incluirVertice(int id) {
    if (!possuiVertice(id)) {
        auto *vertice = new Vertice(id);
        this->vertices.push_back(vertice);

        this->ordem++;
        atualizarSequenciaGraus();

        cout << "Vertice incluido com sucesso." << endl;
    } else {
        cout << "O grafo ja contem dado vertice." << endl;
    }
}

void Grafo::excluirVertice(int id) {
    if (possuiVertice(id)) {
        for (auto i = this->vertices.begin(); i != this->vertices.end();) {
            Vertice *vertice = *i;

            if (vertice->id == id) {
                i = this->vertices.erase(i);
            } else {
                for (auto j = vertice->arestas.begin(); j != vertice->arestas.end(); j++) {
                    Aresta *aresta = *j;

                    if (aresta->verticeAdjacente->id == id) {
                        vertice->arestas.erase(j);
                        break;
                    }
                }

                i++;
            }
        }

        this->ordem--;
        atualizarSequenciaGraus();

        cout << "Vertice excluido com sucesso." << endl;
    } else {
        cout << "O grafo nao contem dado vertice." << endl;
    }
}

Vertice* Grafo::getVertice(int id) {
    for (auto vertice : this->vertices) {
        if (vertice->id == id) {
            return vertice;
        }
    }

    return nullptr;
}

int Grafo::retornarGrauVertice(int id) {
    for (auto vertice : this->vertices) {
        if (vertice->id == id) {
            return vertice->grau;
        }
    }

    return -1;
}

bool Grafo::verificarKRegularidade(int k) {
    for (int grau : this->sequenciaGraus) {
        if (grau != k) {
            return false;
        }
    }

    return true;
}

void Grafo::imprimirVizinhancaAberta(int id) {
    if (possuiVertice(id)) {
        for (auto vertice : this->vertices) {
            if (vertice->id == id) {
                cout << "Vizinhanca aberta do vertice " << vertice->id << ": ";
                vertice->imprimirAdjacentes();
            }
        }
    } else {
        cout << "O grafo nao contem dado vertice." << endl;
    }
}

void Grafo::imprimirVizinhancaFechada(int id) {
    if (possuiVertice(id)) {
        for (auto vertice : this->vertices) {
            if (vertice->id == id) {
                cout << "Vizinhanca aberta do vertice " << vertice->id << ": " << vertice->id << " ";
                vertice->imprimirAdjacentes();
            }
        }
    } else {
        cout << "O grafo nao contem dado vertice." << endl;
    }
}

bool Grafo::verificarGrafoCompleto() {
    for (int grau : this->sequenciaGraus) {
        if (grau != this->ordem - 1) {
            return false;
        }
    }

    return true;
}

bool Grafo::verificarGrafoBipartido() {
    enum Flag {
        SEM_PARTICAO,
        PRIMEIRA_PARTICAO,
        SEGUNDA_PARTICAO,
    };

    for (auto vertice : this->vertices) {
        if(vertice->bipartidoFlag == Flag::SEM_PARTICAO) {
            vertice->bipartidoFlag = Flag::PRIMEIRA_PARTICAO;
        }

        for (auto aresta : vertice->arestas) {
            if (aresta->verticeAdjacente->bipartidoFlag == Flag::SEM_PARTICAO) {
                if (vertice->bipartidoFlag == Flag::PRIMEIRA_PARTICAO) {
                    aresta->verticeAdjacente->bipartidoFlag = Flag::SEGUNDA_PARTICAO;
                } else {
                    aresta->verticeAdjacente->bipartidoFlag = Flag::PRIMEIRA_PARTICAO;
                }
            } else if (aresta->verticeAdjacente->bipartidoFlag == vertice->bipartidoFlag) {
                return false;
            }
        }
    }

    return true;
}

void Grafo::imprimirSequenciaGraus() {
    if (this->ordem > 0) {
        cout << "Sequencia de graus do grafo: ";

        for (int grau : this->sequenciaGraus) {
            cout << grau << " ";
        }

        cout << endl;
    } else {
        cout << "O grafo nao contem nenhum vertice." << endl;
    }
}
