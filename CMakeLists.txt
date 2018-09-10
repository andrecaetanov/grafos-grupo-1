cmake_minimum_required(VERSION 3.12)
project(grafos_grupo_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(grafos_grupo_1 main.cpp Componentes/Vertice.cpp Componentes/Vertice.h Componentes/Aresta.cpp Componentes/Aresta.h Componentes/Grafo.cpp Componentes/Grafo.h)