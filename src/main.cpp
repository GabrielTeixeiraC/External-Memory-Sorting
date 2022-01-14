#include <iostream>
#include "geradorderodadas.h"
using namespace std;

int main(){
    GeradorDeRodadas gerador = GeradorDeRodadas("./tmp/test.txt", 5);
    Entidade entidades[5];
    gerador.leEntidades(entidades);
    gerador.ordena(entidades);
    gerador.escreve(entidades, 1);
    
    return 0;
}