#include <iostream>
#include "geradorderodadas.h"
#include "heap.h"
using namespace std;

int main(){
    GeradorDeRodadas gerador = GeradorDeRodadas("./tmp/test.txt", 5);
    Entidade entidades[5];
    Entidade fita[5];
    gerador.leEntidades(entidades);
    gerador.ordena(entidades);
    gerador.escreve(entidades, 1);
    
    Heap heap(5);
    heap.adiciona(entidades[4]);
    heap.adiciona(entidades[0]);
    heap.adiciona(entidades[3]);
    heap.adiciona(entidades[2]);
    heap.adiciona(entidades[1]);
    Entidade aux = heap.remove();
    aux = heap.remove();
    aux = heap.remove();
    aux = heap.remove();
    aux = heap.remove();


    return 0;
}