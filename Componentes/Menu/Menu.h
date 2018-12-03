//
// Created by andre on 17/09/2018.
//

#ifndef GRAFOS_GRUPO_1_MENU_H
#define GRAFOS_GRUPO_1_MENU_H

#include <string>
#include <iostream>

#include "../Grafo/Grafo.h"
#include "../../Algoritmos/AlgoritmoKruskal.h"
#include "../../Algoritmos/AlgoritmoPrim.h"
#include "../../Algoritmos/AlgoritmoDijkstra.h"

using namespace std;

class Menu {
public:
    static void exibirOpcoes();
    static void selecionarOpcao(Grafo &grafo);
    static void selecionarOutraOpcao(Grafo &grafo);
};


#endif //GRAFOS_GRUPO_1_MENU_H
