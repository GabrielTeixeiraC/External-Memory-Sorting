//---------------------------------------------------------------------
// Arquivo	: quicksort.cpp
// Conteudo	: implementacao do quicksort
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "quicksort.h"

QuickSort::QuickSort(int tamanhoVetor){
    this->tamanhoVetor = tamanhoVetor;
}

void QuickSort::Particao(int Esq, int Dir, int *i, int *j, Entidade entidades[]){
    int x, w;
    *i = Esq; 
    *j = Dir;
    x = entidades[(*i + *j)/2].numeroDeVisitas; /* obtem o pivo x */
    do { 
        while (x > entidades[*i].numeroDeVisitas){
            (*i)++;
        }
        while (x < entidades[*j].numeroDeVisitas) {
            (*j)--;
        }
        if (*i <= *j){
            w = entidades[*i].numeroDeVisitas;
            entidades[*i].numeroDeVisitas = entidades[*j].numeroDeVisitas;
            entidades[*j].numeroDeVisitas = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void QuickSort::Ordena(int Esq, int Dir,  Entidade entidades[]){
    int i, j;
    Particao(Esq, Dir, &i, &j, entidades);
    if (Esq < j) Ordena(Esq, j, entidades);
    if (i < Dir) Ordena(i, Dir, entidades);
}

void QuickSort::OrdenaQuickSort(Entidade entidades[]){
    int indiceFinal = this->tamanhoVetor - 1;
    Ordena(0, indiceFinal, entidades);
}