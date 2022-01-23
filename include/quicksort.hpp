//---------------------------------------------------------------------
// Arquivo	: quicksort.h
// Conteudo	: definicao da classe do quicksort
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------
#ifndef QUICKSORTH
#define QUICKSORTH

#include <iostream>
#include "entidade.hpp"

using namespace std;

class QuickSort {
    public:
        QuickSort(int tamanhoVetor);
        void OrdenaQuickSort(Entidade * entidades);
        void Ordena(int Esq, int Dir,  Entidade * entidades);
        void Particao(int Esq, int Dir, int *i, int *j, Entidade * entidades);
    protected:
        int tamanhoVetor;
};

#endif
