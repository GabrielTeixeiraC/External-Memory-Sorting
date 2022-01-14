//---------------------------------------------------------------------
// Arquivo	: geradorderodadas.h
// Conteudo	: definicao da classe do gerador de rodadas 
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------
#ifndef GERADORDERODADASH
#define GERADORDERODADASH

#include <iostream>
#include <string>
#include "entidade.h"
using namespace std;


class GeradorDeRodadas {
    public:
        GeradorDeRodadas(string nomeArquivoDeEntrada, int numeroDeEntidades);
        void leEntidades(Entidade entidades[]);
        void ordena(Entidade entidades[]);
        void escreve(Entidade* entidades, int numeroDaRodada);
    protected:
        string nomeArquivoDeEntrada;
        int numeroDeEntidades;
};

#endif
