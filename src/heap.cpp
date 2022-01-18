//---------------------------------------------------------------------
// Arquivo	: heap.cpp
// Conteudo	: implementacao do heap
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "heap.h"

Heap::Heap(int tamanhoDoHeap){
    this->tamanhoMaximoDoHeap = tamanhoDoHeap;
    this->numeroDeEntidades = 0;
    heapDeEntidades = new Entidade[tamanhoMaximoDoHeap];
}

Heap::~Heap(){
    delete this->heapDeEntidades;
}

void Heap::refaz(int Esq, int Dir){
    int i, j; 
    Entidade x;
    i = Esq;
    j = (i * 2) + 1;
    x = heapDeEntidades[i];
    while (j <= Dir){
        if (j < Dir){
            if (heapDeEntidades[j].numeroDeVisitas < heapDeEntidades[j + 1].numeroDeVisitas) j++;
        }
        if (x.numeroDeVisitas >= heapDeEntidades[j].numeroDeVisitas) break;
        heapDeEntidades[i] = heapDeEntidades[j];
        i = j;
        j = (i * 2) + 1;
    }
    heapDeEntidades[i] = x;
}

void Heap::adiciona(Entidade entidade){
    if (numeroDeEntidades == tamanhoMaximoDoHeap){
            cerr << "Heap cheio";
            return;
        }
    
        numeroDeEntidades++;
        int final = numeroDeEntidades - 1;
        heapDeEntidades[final] = entidade;
        
        refaz(0, final);
}

Entidade Heap::remove(){
    Entidade aux = heapDeEntidades[0];
    heapDeEntidades[0] = heapDeEntidades[numeroDeEntidades - 1];
    numeroDeEntidades--;
    refaz(0, numeroDeEntidades - 1);
    return aux;
}