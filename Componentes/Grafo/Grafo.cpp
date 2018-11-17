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
                for (auto j = vertice->verticesAdjacentes.begin(); j != vertice->verticesAdjacentes.end(); j++) {
                    Vertice *verticeAdjacente = *j;

                    if (verticeAdjacente->id == id) {
                        verticeAdjacente->verticesAdjacentes.erase(j);
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

bool Grafo::possuiAresta(int id1, int id2) {
    for (auto aresta: this->arestas) {
        if ((aresta->vertice1->id == id1 && aresta->vertice2->id == id2)
            || (aresta->vertice2->id == id1 && aresta->vertice1->id == id2)) {
            return true;
        }
    }

    return false;
}

void Grafo::incluirAresta(int id1, int id2, int peso) {
    if (!this->possuiAresta(id1, id2)) {
        if (!this->possuiVertice(id1)) {
            this->incluirVertice(id1);
        }

        if (!this->possuiVertice(id2)) {
            this->incluirVertice(id2);
        }

        Vertice *vertice1 = this->getVertice(id1);
        Vertice *vertice2 = this->getVertice(id2);

        auto *aresta = new Aresta(vertice1, vertice2, peso);
        this->arestas.push_back(aresta);

        vertice1->verticesAdjacentes.push_back(vertice2);
        vertice1->grau++;

        vertice2->verticesAdjacentes.push_back(vertice1);
        vertice2->grau++;

        atualizarSequenciaGraus();

        cout << "Aresta incluida com sucesso." << endl;
    } else {
        cout << "O grafo ja contem dada aresta." << endl;
    }
}

void Grafo::excluirAresta(int id1, int id2) {
    if (this->possuiAresta(id1, id2)) {
        for (auto i = this->arestas.begin(); i != this->arestas.end(); i++) {
            Aresta *aresta = *i;
            Vertice *vertice1 = aresta->vertice1;
            Vertice *vertice2 = aresta->vertice2;

            if ((vertice1->id == id1 && vertice2->id == id2)
                || (vertice2->id == id1 && vertice1->id == id2)) {
                this->arestas.erase(i);

                vertice1->grau--;
                vertice2->grau--;
            }
        }

        cout << "Aresta excluida com sucesso." << endl;

    } else {
        cout << "O grafo nao contem dada aresta." << endl;
    }
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

        for (auto verticeAdjacente : vertice->verticesAdjacentes) {
            if (verticeAdjacente->bipartidoFlag == Flag::SEM_PARTICAO) {
                if (vertice->bipartidoFlag == Flag::PRIMEIRA_PARTICAO) {
                    verticeAdjacente->bipartidoFlag = Flag::SEGUNDA_PARTICAO;
                } else {
                    verticeAdjacente->bipartidoFlag = Flag::PRIMEIRA_PARTICAO;
                }
            } else if (verticeAdjacente->bipartidoFlag == vertice->bipartidoFlag) {
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

bool Grafo::ehConexo() {
    return true;
}
