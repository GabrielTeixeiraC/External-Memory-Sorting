//---------------------------------------------------------------------
// Arquivo	: geradorderodadas.cpp
// Conteudo	: implementacao do gerador de rodadas 
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "geradorderodadas.h"
#include "entidade.h"
#include "quicksort.h"
#include "msgassert.h"

using namespace std;

GeradorDeRodadas::GeradorDeRodadas(string nomeArquivoDeEntrada, int numeroDeEntidades){
    this->nomeArquivoDeEntrada = nomeArquivoDeEntrada;
    this->numeroDeEntidades = numeroDeEntidades;
}

void GeradorDeRodadas::leEntidades(Entidade entidades[]){
    ifstream arquivoDeEntidades(this->nomeArquivoDeEntrada.c_str());
    if (arquivoDeEntidades.is_open()){
        
        string linha;

        string url;
        unsigned long numeroDeVisitas;
        
        for (int i = 0; i < this->numeroDeEntidades; i++){
            getline(arquivoDeEntidades, linha);
            
            int separacaoUrlNumero = linha.find(" ");

            url = linha.substr(0, separacaoUrlNumero);
            numeroDeVisitas = stoul(linha.substr(separacaoUrlNumero, linha.size()));
        
            Entidade aux;

            aux.url = url;
            aux.numeroDeVisitas = numeroDeVisitas;

            entidades[i] = aux; 
        }
    }
    else{
        erroAssert(arquivoDeEntidades.is_open(), "Arquivo com entidades não foi aberto");
    }    
}

void GeradorDeRodadas::ordena(Entidade entidades[]) {
    QuickSort ordenadorQuickSort = QuickSort(this->numeroDeEntidades);
    ordenadorQuickSort.OrdenaQuickSort(entidades);
}

void GeradorDeRodadas::escreve(Entidade entidades[], int numeroDaRodada){
    string nomeDoArquivoDeSaida = "./tmp/rodada-";
    nomeDoArquivoDeSaida.append(to_string(numeroDaRodada));
    nomeDoArquivoDeSaida.append(".txt");
    
    ofstream arquivoDeSaida(nomeDoArquivoDeSaida);

    for (int i = 0; i < this->numeroDeEntidades; i++){
        arquivoDeSaida << entidades[i].url << " " << entidades[i].numeroDeVisitas << endl;
    }
    
}
