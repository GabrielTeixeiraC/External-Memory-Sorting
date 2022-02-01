//---------------------------------------------------------------------
// Arquivo	: entidade.h
// Conteudo	: definicao da struct entidade
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------
#ifndef ENTIDADEH
#define ENTIDADEH

#include <iostream>
#include <string>
using namespace std;

// Entidade: guarda uma url, o numero de visitas e o numero da fita na hora de intercalar
struct Entidade {
    string url;
    int numeroDeVisitas;
    int numeroDaFita;

    Entidade(){
        url = "";
        numeroDeVisitas = 0;
        numeroDaFita = 0;
    }
};

#endif
