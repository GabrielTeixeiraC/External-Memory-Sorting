//---------------------------------------------------------------------
// Arquivo	: heap.cpp
// Conteudo	: definicao da classe do heap
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#ifndef HEAPH
#define HEAPH



#include <iostream>
#include <string>
#include "entidade.h"
using namespace std;


class Heap {
    public:
        Heap(int tamanhoDoHeap);
        ~Heap();
        void refaz(int Esq, int Dir);
        void adiciona(Entidade entidade);
        Entidade remove();
        Entidade* heapDeEntidades;
    protected:
        int numeroDeEntidades;
        int tamanhoMaximoDoHeap;
};

#endif
