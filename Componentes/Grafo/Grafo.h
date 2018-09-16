//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_GRAFO_H
#define GRAFOS_GRUPO_1_GRAFO_H

#include <list>
#include <iostream>

#include "Vertice.h"

using namespace std;

class Grafo {
public:
    int ordem;
    list<Vertice *> vertices;
    list<int> sequenciaGraus;

    Grafo();
    ~Grafo() = default;
    void atualizarSequenciaGraus();
    bool possuiVertice(int id);
    void incluirVertice(int id);
    void excluirVertice(int id);
    Vertice* getVertice(int id);
    int retornarGrauVertice(int id);
    bool verificarKRegularidade(int k);
};


#endif //GRAFOS_GRUPO_1_GRAFO_H
