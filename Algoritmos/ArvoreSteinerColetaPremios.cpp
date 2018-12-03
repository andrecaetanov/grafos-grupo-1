//
// Created by andre on 17/11/2018.
//

#include "ArvoreSteinerColetaPremios.h"

void ArvoreSteinerColetaPremios::algoritmoGuloso(Grafo *grafo) {
    calcularBeneficioVertices(grafo);

    // define o primeiro vértice da lista ordenada como vértice inicial
    Vertice *verticeInicial = grafo->vertices.front();

    Grafo *solucao = obterSolucao(grafo, verticeInicial);

    imprimirSolucao(solucao);
}

void ArvoreSteinerColetaPremios::algoritmoGulosoRandomizado(Grafo *grafo, float alfa, int numIteracoes) {
    auto *melhorSolucao = new Grafo();
    melhorSolucao->custo = numeric_limits<int>::max();

    calcularBeneficioVertices(grafo);

    int posicaoMaximaVertice = static_cast<int>(grafo->vertices.size() * alfa + 1);

    for (int iteracao = 0; iteracao < numIteracoes; iteracao++) {
        Grafo *solucao = obterSolucaoRandomizado(grafo, posicaoMaximaVertice);

        if (solucao->custo < melhorSolucao->custo) {
            melhorSolucao = new Grafo(*solucao);
        }
    }

    imprimirSolucao(melhorSolucao);
}

void ArvoreSteinerColetaPremios::algoritmoGulosoRandomizadoReativo(Grafo *grafo, int numBlocos, int iteracoesBloco, int sigma) {
    auto *melhorSolucao = new Grafo();
    melhorSolucao->custo = numeric_limits<int>::max();

    calcularBeneficioVertices(grafo);

    Alfa alfas[10] = {{0, 0.1, 0.1, 0, 0}, {1, 0.2, 0.10, 0, 0}, {2, 0.3, 0.1,  0, 0}, {3, 0.4, 0.1, 0, 0}, {4, 0.5, 0.1, 0, 0},
                      {5, 0.6, 0.1,  0, 0}, {6, 0.7, 0.1, 0, 0}, {7, 0.8, 0.1,  0, 0}, {8, 0.9, 0.1,  0, 0}, {9, 1, 0.1, 0, 0}};

    for (int bloco = 0; bloco < numBlocos; bloco++) {
        auto *melhorSolucaoBloco = new Grafo();
        melhorSolucaoBloco->custo = numeric_limits<int>::max();

        Alfa alfa = escolherAlfaAleatorio(alfas);

        int posicaoMaximaVertice = static_cast<int>(grafo->vertices.size() * alfa.valor + 1);

        for (int iteracao = 0; iteracao < iteracoesBloco; iteracao++) {
            Grafo *solucao = obterSolucaoRandomizado(grafo, posicaoMaximaVertice);

            alfa.somaCustosSolucoes += solucao->custo;

            if (solucao->custo < melhorSolucaoBloco->custo) {
                melhorSolucaoBloco = new Grafo(*solucao);
            }
        }

        alfa.mediaCustosSolucoes = alfa.somaCustosSolucoes / (float) (alfa.numVezesSelecionado * iteracoesBloco);
        alfas[alfa.indice] = alfa;

        atualizarProbabilidadesAlfas(alfas, melhorSolucao->custo, sigma);

        if (melhorSolucaoBloco->custo < melhorSolucao->custo) {
            melhorSolucao = new Grafo(*melhorSolucaoBloco);
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

    // ordena vértices do grafo por benefício em ordem decrescente
    grafo->vertices.sort([](Vertice *vertice1, Vertice *vertice2) {
        return vertice1->beneficio > vertice2->beneficio;
    });
}

Grafo *ArvoreSteinerColetaPremios::obterSolucaoRandomizado(Grafo *grafo, int posicaoMaximaVertice) {
    int posicaoVerticeInicial = rand() % posicaoMaximaVertice;
    auto *verticeInicial = new Vertice();

    int posicao = 0;
    for (auto vertice : grafo->vertices) {
        if (posicao == posicaoVerticeInicial) {
            verticeInicial = vertice;
            break;
        }

        posicao++;
    }

    Grafo *solucao = obterSolucao(grafo, verticeInicial);
    return solucao;
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

ArvoreSteinerColetaPremios::Alfa ArvoreSteinerColetaPremios::escolherAlfaAleatorio(Alfa *alfas) {
    return alfas[0]; // return temporário
}

void ArvoreSteinerColetaPremios::atualizarProbabilidadesAlfas(Alfa *alfas, int custoMelhorSolucao, int sigma) {
    double q[10];

    for (int i = 0; i < 10; i++) {
        q[i] = pow(custoMelhorSolucao/alfas[i].mediaCustosSolucoes, sigma);
    }

    double somaQ = 0;
    for (auto qi : q) {
        somaQ += qi;
    }

    for (int i = 0; i < 10; i++) {
        alfas[i].probabilidade = q[i]/somaQ;
    }
}
