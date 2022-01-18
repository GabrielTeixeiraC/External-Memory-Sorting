//---------------------------------------------------------------------
// Arquivo	: intercalador.cpp
// Conteudo	: definicao da classe do intercalador
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------
#ifndef INTERCALADORH
#define INTERCALADORH

#include <iostream>
#include <string>
#include "entidade.h"
using namespace std;


class Intercalador {
    public:
        Intercalador();
        void intercala();
    protected:
        string nomeArquivoDeEntrada;
        int numeroDeEntidades;
};

#endif
