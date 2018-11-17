//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_GRAFO_H
#define GRAFOS_GRUPO_1_GRAFO_H

#include <list>
#include <iostream>

#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo {
public:
    int ordem;
    list<Vertice *> vertices;
    list<Aresta *> arestas;
    list<int> sequenciaGraus;

    Grafo();
    ~Grafo() = default;

    // Funcionalidades exigidas
    void incluirVertice(int id);
    void excluirVertice(int id);
    void incluirAresta(int id1, int id2, int peso);
    void excluirAresta(int id1, int id2);
    int retornarGrauVertice(int id);
    bool verificarKRegularidade(int k);
    void imprimirVizinhancaAberta(int id);
    void imprimirVizinhancaFechada(int id);
    bool verificarGrafoCompleto();
    bool verificarGrafoBipartido();
    void imprimirSequenciaGraus();

    // Funções auxiliares
    void atualizarSequenciaGraus();
    bool possuiVertice(int id);
    Vertice* getVertice(int id);
    bool possuiAresta(int id1, int id2);
    bool ehConexo();
};


#endif //GRAFOS_GRUPO_1_GRAFO_H
