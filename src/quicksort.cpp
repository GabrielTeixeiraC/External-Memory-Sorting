//---------------------------------------------------------------------
// Arquivo	: quicksort.cpp
// Conteudo	: implementacao do quicksort
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <string.h>
#include "quicksort.hpp"
#include "memlog.hpp"

// construtor da classe QuickSort
QuickSort::QuickSort(int tamanhoVetor){
    this->tamanhoVetor = tamanhoVetor;
}

// Descricao: método que particiona o vetor de acordo com um pivô
// Entrada: Esq, Dir, i, j, entidades
// Saida: -
void QuickSort::Particao(int Esq, int Dir, int *i, int *j, Entidade * entidades){
    Entidade esquerda, meio, direita, pivo, aux;
    *i = Esq; 
    *j = Dir;
    
    // define o pivô como a mediana entre os valores nas extremidades e o valor
    // no meio do intervalo, evitando o pior caso do QuickSort
    esquerda = entidades[*i];
    leMemLog( (long int) (&entidades[*i]), sizeof(Entidade), 0);
    escreveMemLog( (long int) (&esquerda), sizeof(Entidade), 0);

    meio = entidades[(*i + *j)/2];
    leMemLog( (long int) (&entidades[(*i + *j)/2]), sizeof(Entidade), 0);
    escreveMemLog( (long int) (&meio), sizeof(Entidade), 0);

    direita = entidades[*j];
    leMemLog( (long int) (&entidades[*j]), sizeof(Entidade), 0);
    escreveMemLog( (long int) (&direita), sizeof(Entidade), 0);
    
    if(esquerda.numeroDeVisitas >= meio.numeroDeVisitas && esquerda.numeroDeVisitas >= direita.numeroDeVisitas) {
        if(meio.numeroDeVisitas >= direita.numeroDeVisitas) {
            pivo = meio;
            leMemLog( (long int) (&meio), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
        else {
            pivo = direita;
            leMemLog( (long int) (&direita), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
    }
    else if(meio.numeroDeVisitas >= esquerda.numeroDeVisitas && meio.numeroDeVisitas >= direita.numeroDeVisitas) {
        if(esquerda.numeroDeVisitas >= direita.numeroDeVisitas) {
            pivo = esquerda;
            leMemLog( (long int) (&esquerda), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
        else {
            pivo = direita;
            leMemLog( (long int) (&direita), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
    }
    else {
        if(esquerda.numeroDeVisitas >= meio.numeroDeVisitas) {
            pivo = esquerda;

            leMemLog( (long int) (&esquerda), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
        else {
            pivo = meio;

            leMemLog( (long int) (&meio), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&pivo), sizeof(Entidade), 0);
        } 
    }

    // passa elementos maiores que o pivô para a sua esquerda e
    // os elementos menores que o pivô para a sua direita
    do { 
        // para no primeiro elemento à esquerda do pivô que é menor do que ele ou
        // é igual e possui url >= à do pivô
        while (entidades[*i].numeroDeVisitas >= pivo.numeroDeVisitas){
            if (entidades[*i].numeroDeVisitas == pivo.numeroDeVisitas){
                if (strcmp(entidades[*i].url.c_str(), pivo.url.c_str()) >= 0){
                    break;
                } 
                else{
                    (*i)++;
                }
            }
            else{
                (*i)++;
            }
        }
        // para no primeiro elemento à direita do pivô que é maior do que ele ou
        // é igual e possui url <= à do pivô
        // a  b  c  d 
        while (entidades[*j].numeroDeVisitas <= pivo.numeroDeVisitas) {
            if (entidades[*j].numeroDeVisitas == pivo.numeroDeVisitas){
                if (strcmp(entidades[*j].url.c_str(), pivo.url.c_str()) <= 0){
                    break;
                } 
                else{
                    (*j)--;
                } 
            }
            else{
                (*j)--;
            }
        }
        // troca de lado os elementos identificados pelos loops acima
        if (*i <= *j){
            aux = entidades[*i];
            leMemLog( (long int) (&entidades[*i]), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&aux), sizeof(Entidade), 0);

            entidades[*i] = entidades[*j];
            leMemLog( (long int) (&entidades[*j]), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&entidades[*i]), sizeof(Entidade), 0);

            entidades[*j] = aux;
            leMemLog( (long int) (&aux), sizeof(Entidade), 0);
            escreveMemLog( (long int) (&entidades[*j]), sizeof(Entidade), 0);

            (*i)++; 
            (*j)--;

        }
    } while (*i <= *j);
}

// Descricao: método que particiona e ordena o vetor recursivamente
// Entrada: Esq, Dir, entidades
// Saida: -
void QuickSort::Ordena(int Esq, int Dir, Entidade * entidades){
    int i, j;
    // particiona o vetor
    Particao(Esq, Dir, &i, &j, entidades);
    
    // chama o método de ordenação recursivamente em cada partição do vetor
    if (Esq < j) Ordena(Esq, j, entidades);
    if (i < Dir) Ordena(i, Dir, entidades);
}

// Descricao: método que ordena o vetor de entidades
// Entrada: entidades
// Saida: -
void QuickSort::OrdenaQuickSort(Entidade * entidades){
    int indiceFinal = this->tamanhoVetor - 1;
    Ordena(0, indiceFinal, entidades);
}