//
// Created by andre on 17/11/2018.
//

#include "ArvoreSteinerColetaPremios.h"

void ArvoreSteinerColetaPremios::algoritmoGuloso(Grafo *grafo) {
    calcularBeneficioVertices(grafo);

    // ordena vértices do grafo por benefício em ordem decrescente
    grafo->vertices.sort([](Vertice *vertice1, Vertice *vertice2) {
        return vertice1->beneficio > vertice2->beneficio;
    });

    // define o primeiro vértice da lista ordenada como vértice inicial
    Vertice *verticeInicial = grafo->vertices.front();

    Grafo *solucao = obterSolucao(grafo, verticeInicial);

    imprimirSolucao(solucao);
}

void ArvoreSteinerColetaPremios::algoritmoGulosoRandomizado(Grafo *grafo, float alcanceRandom, int numIteracoes) {
    auto *melhorSolucao = new Grafo();
    melhorSolucao->custo = numeric_limits<int>::max();

    calcularBeneficioVertices(grafo);

    // ordena vértices do grafo por benefício em ordem decrescente
    grafo->vertices.sort([](Vertice *vertice1, Vertice *vertice2) {
        return vertice1->beneficio > vertice2->beneficio;
    });

    int posicaoMaximaVertice = static_cast<int>(grafo->vertices.size() * (alcanceRandom / 100) + 1);

    for (int iteracao = 0; iteracao < numIteracoes; iteracao++) {
        int posicaoVerticeInicial = rand() % posicaoMaximaVertice;
        auto *verticeInicial = new Vertice();

        int posicao = 0;
        for (auto vertice : grafo->vertices) {
            if (posicao == posicaoVerticeInicial) {
                verticeInicial = vertice;
            }

            posicao++;
        }

        Grafo *solucao = obterSolucao(grafo, verticeInicial);

        if (solucao->custo < melhorSolucao->custo) {
            melhorSolucao = new Grafo(*solucao);
        }
    }

    imprimirSolucao(melhorSolucao);
}

void ArvoreSteinerColetaPremios::calcularBeneficioVertices(Grafo *grafo) {
    for (auto vertice : grafo->vertices) {
        int somaPesoArestas = 0;

        for (auto aresta : vertice->arestas) {
            somaPesoArestas += aresta->peso;
        }

        float mediaPesoArestas = (float) somaPesoArestas/vertice->grau;

        vertice->beneficio = vertice->peso/mediaPesoArestas; // função critério
    }
}

Grafo *ArvoreSteinerColetaPremios::obterSolucao(Grafo *grafo, Vertice *verticeInicial) {
    auto solucao = new Grafo();
    solucao->vertices.push_back(verticeInicial);

    calcularCustoSolucao(grafo, solucao);

    auto melhorSolucao = new Grafo(*solucao);

    while (solucao->vertices.size() < grafo->vertices.size()) {
        incluirVerticeSolucao(solucao);

        calcularCustoSolucao(grafo, solucao);

        if (solucao->custo < melhorSolucao->custo) {
            melhorSolucao = new Grafo(*solucao);
        }
    }
    return melhorSolucao;
}

void ArvoreSteinerColetaPremios::calcularCustoSolucao(Grafo *grafo, Grafo *solucao) {
    solucao->custo = 0;

    for (auto vertice : grafo->vertices) {
        if (!solucao->possuiVertice(vertice->id)) {
            solucao->custo += vertice->peso;
        }
    }

    for (auto aresta : solucao->arestas) {
        solucao->custo += aresta->peso;
    }
}

void ArvoreSteinerColetaPremios::incluirVerticeSolucao(Grafo *solucao) {
    list<Vertice *> verticesCandidatos;

    for (auto vertice : solucao->vertices) {
        for (auto verticeAdjacente : vertice->verticesAdjacentes) {
            if (!solucao->possuiVertice(verticeAdjacente->id)) {
                verticesCandidatos.push_back(verticeAdjacente);
            }
        }
    }

    // ordena os vértices candidatos por benefício em ordem decrescente
    verticesCandidatos.sort([](Vertice *vertice1, Vertice *vertice2) {
        return vertice1->beneficio > vertice2->beneficio;
    });

    Vertice *verticeMaiorBeneficio = verticesCandidatos.front();

    auto *arestaMenorPeso = new Aresta();
    arestaMenorPeso->peso = numeric_limits<int>::max();

    for (auto aresta : verticeMaiorBeneficio->arestas) {
        if (solucao->possuiVertice(aresta->vertice1->id) || solucao->possuiVertice(aresta->vertice2->id)) {
            if (aresta->peso < arestaMenorPeso->peso) {
                arestaMenorPeso = aresta;
            }
        }
    }

    solucao->vertices.push_back(verticeMaiorBeneficio);
    solucao->arestas.push_back(arestaMenorPeso);
}

void ArvoreSteinerColetaPremios::imprimirSolucao(Grafo *solucao) {
    cout << "Solucao para o problema ASCP (PCST) encontrada:" << endl;

    cout << "Custo: " << solucao->custo << endl;

    cout << "Vertices: ";
    for (auto vertice : solucao->vertices) {
        cout << vertice->id << ", ";
    }
    cout << endl;

    cout << "Arestas: ";
    for (auto aresta : solucao->arestas) {
        cout << "(" << aresta->vertice1->id << "," << aresta->vertice2->id << ") ";
    }
    cout << endl;
}
