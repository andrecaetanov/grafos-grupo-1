//
// Created by andre on 10/09/2018.
//

#include "Vertice.h"

Vertice::Vertice(int id, double peso) {
    this->id = id;
    this->grau = 0;
    this->peso = peso;
}

Vertice::Vertice(double peso) {
    this->grau = 0;
    this->peso = peso;
}
