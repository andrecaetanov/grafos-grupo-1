//
// Created by andre on 10/09/2018.
//

#ifndef GRAFOS_GRUPO_1_LEITORARQUIVO_H
#define GRAFOS_GRUPO_1_LEITORARQUIVO_H

#include <string>
#include <iostream>
#include <fstream>
#include <list>

#include "../Grafo/Grafo.h"
#include "../Grafo/Aresta.h"

class LeitorArquivo {
public:
    static void lerArquivo(std::string caminhoArquivo, Grafo &grafo);
    static void atribuirDados(std::ifstream &arquivo, Grafo &grafo);
};


#endif //GRAFOS_GRUPO_1_LEITORARQUIVO_H
