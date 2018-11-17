//
// Created by andre on 16/11/2018.
//

#ifndef GRAFOS_GRUPO_1_ALGORITMOKRUSKAL_H
#define GRAFOS_GRUPO_1_ALGORITMOKRUSKAL_H

#include <list>

#include "../Componentes/Grafo/Grafo.h"

using namespace std;

class AlgoritmoKruskal {
public:
    static void encontrarArvoreGeradoraMinima(Grafo *grafo);
    static bool arestaFormaCiclo(Vertice *vertice1, Vertice *vertice2);
    static void imprimirSolucao(Grafo *Grafo);
};


#endif //GRAFOS_GRUPO_1_ALGORITMOKRUSKAL_H
