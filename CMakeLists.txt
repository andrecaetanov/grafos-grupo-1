cmake_minimum_required(VERSION 3.12)
project(grafos_grupo_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(grafos_grupo_1 main.cpp Componentes/Grafo/Vertice.cpp Componentes/Grafo/Vertice.h Componentes/Grafo/Aresta.cpp Componentes/Grafo/Aresta.h Componentes/Grafo/Grafo.cpp Componentes/Grafo/Grafo.h Componentes/LeitorArquivo/LeitorArquivo.cpp Componentes/LeitorArquivo/LeitorArquivo.h Componentes/Menu/Menu.cpp Componentes/Menu/Menu.h Algoritmos/AlgoritmoKruskal.cpp Algoritmos/AlgoritmoKruskal.h Algoritmos/AlgoritmoPrim.cpp Algoritmos/AlgoritmoPrim.h Algoritmos/ArvoreSteinerColetaPremios.cpp Algoritmos/ArvoreSteinerColetaPremios.h Algoritmos/AlgoritmoDijkstra.cpp Algoritmos/AlgoritmoDijkstra.h)