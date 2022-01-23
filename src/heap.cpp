//---------------------------------------------------------------------
// Arquivo	: heap.cpp
// Conteudo	: implementacao do heap
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "heap.hpp"
#include "string.h"

// Construtor do heap
Heap::Heap(int tamanhoDoHeap){
    this->tamanhoMaximoDoHeap = tamanhoDoHeap;
    this->numeroDeEntidades = 0;

    // aloca memória dinamicamente para um vetor de entidades com o tamanho máximo especificado
    heapDeEntidades = new Entidade[tamanhoMaximoDoHeap];
}

void Heap::desaloca(){
    delete[] this->heapDeEntidades;
}

// Descricao: método que constrói um heap dado um vetor de entidades
// Entrada: entidades
// Saida: -
void Heap::constroi(){
    int Esq;
    int final = this->numeroDeEntidades - 1;

    Esq = (final + 1) / 2;

    // refaz o heap a partir das entidades que não são folhas
    while (Esq > 0){
        Esq--;
        refaz(Esq, final);
    }
}

// Descricao: método que refaz um heap
// Entrada: Esq, Dir
// Saida: -
void Heap::refaz(int Esq, int Dir){
    int i, j; 
    Entidade x;

    i = Esq;
    j = (i * 2) + 1;
    x = heapDeEntidades[i];

    while (j <= Dir){
        // pega o maior filho do nó
        if (j < Dir){
            if (heapDeEntidades[j + 1].numeroDeVisitas > heapDeEntidades[j].numeroDeVisitas) j++;
            else if (heapDeEntidades[j + 1].numeroDeVisitas == heapDeEntidades[j].numeroDeVisitas){
                if (strcmp(heapDeEntidades[j + 1].url.c_str(), heapDeEntidades[j].url.c_str()) < 0) {
                    j++;
                }
            };
        }

        // quebra o loop se a estrutura do heap estiver correta
        if (x.numeroDeVisitas >= heapDeEntidades[j].numeroDeVisitas) {
            
            // se nóPai.NumeroDeVisitas == nóFilho.numeroDeVisitas && se nóPai.url <= nóFilho.url: OK
            if (x.numeroDeVisitas == heapDeEntidades[j].numeroDeVisitas) {
                if(strcmp(x.url.c_str(), heapDeEntidades[j].url.c_str()) < 0) {
                    break;
                }
            }

            // se nóPai.numeroDeVisitas > nóFilho: OK
            else{
                break;
            } 
        } 

        // coloca a entidade filha no lugar do pai se o filho for maior
        heapDeEntidades[i] = heapDeEntidades[j];
        i = j;
        j = (i * 2) + 1;
    }
    
    // atualiza o valor do filho com a entidade vinda de cima
    heapDeEntidades[i] = x;
}

// Descricao: método que le as entidades de um arquivo de entrada
// Entrada: entidades, arquivoDeEntrada
// Saida: -
void Heap::adiciona(Entidade entidade){
    // atualiza o número de entidades no heap
    numeroDeEntidades++;
    
    // adiciona o elemento no final do heap
    int final = numeroDeEntidades - 1;
    heapDeEntidades[final] = entidade;
    
    // constroi o heap
    constroi();
}

// retorna o número de entidades no Heap
int Heap::getNumeroDeEntidades(){
    return this->numeroDeEntidades;
}

// Descricao: método que remove a entidade do topo do heap
// Entrada: -
// Saida: -
Entidade Heap::remove(){
    // pega o elemento do topo
    Entidade aux = heapDeEntidades[0];
    
    // copia pro topo o elemento no final do heap
    heapDeEntidades[0] = heapDeEntidades[numeroDeEntidades - 1];
    
    // atualiza o número de entidades
    numeroDeEntidades--;

    // refaz o heap
    refaz(0, numeroDeEntidades - 1);
    
    // retorna o elemento que estava no topo do heap
    return aux;
}