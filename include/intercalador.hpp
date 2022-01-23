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
#include "entidade.hpp"
#include "heap.hpp"
using namespace std;


class Intercalador {
    public:
        Intercalador(int numeroDeEntidades, int numeroDeFitas, string nomeArquivoSaida);
        void intercala(ifstream vetorDeArquivos[]);
    protected:
        int numeroDeEntidades;
        int numeroDeFitas;
        string nomeArquivoSaida;
        Heap heapDeEntidades;
};

#endif
