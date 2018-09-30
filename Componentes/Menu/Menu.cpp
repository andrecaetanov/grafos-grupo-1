//
// Created by andre on 17/09/2018.
//

#include "Menu.h"

void Menu::exibirOpcoes() {
    string opcoes[12] = {
            "1 - Incluir vertice",
            "2 - Excluir vertice",
            "3 - Incluir aresta",
            "4 - Excluir aresta",
            "5 - Retornar grau de um vertice",
            "6 - Vertificar a k-regularidade",
            "7 - Informar ordem do grafo",
            "8 - Mostrar a vizinhanca aberta de um vertice",
            "9 - Mostrar a vizinhanca fechada de um vertice",
            "10 - Verificar se o grafo eh completo",
            "11 - Verificar se o grafo eh bipartido",
            "12 - Apresentar a sequencia de graus",
    };

    cout << "MENU:" << endl;

    for (const auto &opcao : opcoes) {
        cout << opcao << endl;
    }
    cout << endl;
}

void Menu::selecionarOpcao(Grafo &grafo) {
    int opcaoDesejada;

    cout << "Informe o valor da opcao desejada:" << endl;
    cin >> opcaoDesejada;

    switch (opcaoDesejada) {
        case 1: {
            int id;

            cout << "Digite o ID do vertice:" << endl;
            cin >> id;

            grafo.incluirVertice(id);
            break;
        }

        case 2: {
            int id;

            cout << "Digite o ID do vertice:" << endl;
            cin >> id;

            grafo.excluirVertice(id);
            break;
        }

        case 3: {
            int id1, id2;

            cout << "Digite os IDs dos vertices:" << endl;
            cin >> id1 >> id2;

            grafo.excluirAresta(id1, id2);
            break;
        }

        case 4: {
            int id1, id2;
            int peso;

            cout << "Digite os IDs dos vertices:" << endl;
            cin >> id1 >> id2;

            cout << "Digite o peso da aresta:" << endl;
            cin >> peso;

            grafo.incluirAresta(id1, id2, peso);
            break;
        }

        case 5: {
            int id;
            int grau;

            cout << "Digite o ID do vertice:" << endl;
            cin >> id;

            grau = grafo.retornarGrauVertice(id);

            if (grau != -1) {
                cout << "Grau do vertice: " << grau << endl;
            } else {
                cout << "O grafo nao contem dado vertice." << endl;
            }
            break;
        }

        case 6: {
            int id;

            cout << "Digite o valor de k:" << endl;
            cin >> id;

            if (grafo.verificarKRegularidade(id)) {
                cout << "O grafo eh k-regular." << endl;
            } else {
                cout << "O grafo nao eh k-regular." << endl;
            }
            break;
        }

        case 7: {
            cout << "Ordem do grafo: " << grafo.ordem << endl;
            break;
        }

        case 8: {
            int id;

            cout << "Digite o ID do vertice:" << endl;
            cin >> id;

            grafo.imprimirVizinhancaAberta(id);
            break;
        }

        case 9: {
            int id;

            cout << "Digite o ID do vertice:" << endl;
            cin >> id;

            grafo.imprimirVizinhancaFechada(id);
            break;
        }

        case 10: {
            if (grafo.verificarGrafoCompleto()) {
                cout << "O grafo eh completo." << endl;
            } else {
                cout << "O grafo nao eh completo." << endl;
            }
            break;
        }

        case 11: {
            if (grafo.verificarGrafoBipartido()) {
                cout << "O grafo eh bipartido." << endl;
            } else {
                cout << "O grafo nao eh bipartido." << endl;
            }
            break;
        }

        case 12: {
            grafo.imprimirSequenciaGraus();
            break;
        }

        default: {
            cout << "Opcao invalida." << endl;
        }
    }

    selecionarOutraOpcao(grafo);
}

void Menu::selecionarOutraOpcao(Grafo &grafo) {
    int opcao;

    cout << "Deseja selecionar outra opcao?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;

    cin >> opcao;

    if (opcao == 1) {
        selecionarOpcao(grafo);
    } else if (opcao == 2) {
        exit(0);
    } else {
        cout << "Opcao invalida." << endl;

        selecionarOutraOpcao(grafo);
    }
}

