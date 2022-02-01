//---------------------------------------------------------------------
// Arquivo	: geradorderodadas.h
// Conteudo	: definicao da classe do gerador de rodadas 
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------
#ifndef GERADORDERODADASH
#define GERADORDERODADASH

#include <iostream>
#include <fstream>
#include <string>
#include "entidade.hpp"
using namespace std;


class GeradorDeRodadas {
    public:
        GeradorDeRodadas(int numeroDeEntidades);
        void leEntidades(Entidade * entidades, ifstream& arquivoDeEntrada);
        void ordena(Entidade * entidades);
        void escreve(Entidade * entidades, int numeroDaRodada);
        bool leituraTerminou();
    protected:
        int numeroDeEntidades;
        bool terminou = 0;
};

#endif
