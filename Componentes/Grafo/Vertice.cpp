//
// Created by andre on 10/09/2018.
//

#include "Vertice.h"

Vertice::Vertice(int id) {
    this->id = id;
    this->grau = 0;
}

Vertice::Vertice(int id, int peso) {
    this->id = id;
    this->peso = peso;
    this->grau = 0;
}
