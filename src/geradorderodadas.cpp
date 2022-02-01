//---------------------------------------------------------------------
// Arquivo	: geradorderodadas.cpp
// Conteudo	: implementacao do gerador de rodadas 
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "geradorderodadas.hpp"
#include "msgassert.hpp"
#include "entidade.hpp"
#include "quicksort.hpp"
#include "memlog.hpp"

using namespace std;

// Construtor do gerador de rodadas
GeradorDeRodadas::GeradorDeRodadas(int numeroDeEntidades){
    this->numeroDeEntidades = numeroDeEntidades;
}

// Descricao: método que le as entidades de um arquivo de entrada
// Entrada: entidades, arquivoDeEntrada
// Saida: -
void GeradorDeRodadas::leEntidades(Entidade * entidades, ifstream& arquivoDeEntrada){
    // lê de um arquivo o número de entidades passado como parâmetro
    for (int i = 0; i < this->numeroDeEntidades; i++){
        string url = "";
        unsigned long numeroDeVisitas = 0;
        arquivoDeEntrada >> url >> numeroDeVisitas;
        if (!arquivoDeEntrada.eof()) {
            // asserção de leitura correta de entidade
            erroAssert(arquivoDeEntrada.good(), "Leitura inválida de entidade");
            
            // asserção de tamanho da url válido
            erroAssert(url.size() > 0, "Url não pode ser vazia.");
            
            // asserção de leitura de número de visitas positivo
            erroAssert(numeroDeVisitas >= 0, "Número de visitas deve ser positivo");

            // atribuição da entidade lida no vetor  
            Entidade aux;

            aux.url = url;
            escreveMemLog( (long int) (&aux.url), sizeof(string), 1);
            aux.numeroDeVisitas = numeroDeVisitas;
            escreveMemLog( (long int) (&aux.numeroDeVisitas), sizeof(unsigned long), 1);

            entidades[i] = aux; 
            leMemLog( (long int) (&aux), sizeof(Entidade), 1);
            escreveMemLog( (long int) (&entidades[i]), sizeof(Entidade), 1);

        }
        
        // quebra o loop se estiver no fim do arquivo e checa se a leitura foi vazia.
        else {
            if (i == 0){
                this->terminou = true;
            }
            break;
        }
    }

}

// Descricao: método que ordena um vetor de entidades de acordo com o número de visitas
// Entrada: entidades
// Saida: -
void GeradorDeRodadas::ordena(Entidade * entidades) {
    // instanciação do objeto ordenador
    QuickSort ordenadorQuickSort = QuickSort(this->numeroDeEntidades);
    // chama o método ordenador
    ordenadorQuickSort.OrdenaQuickSort(entidades);
}

// Descricao: método que escreve em vários arquivos as entidades em ordem decrescente
// Entrada: entidades, numeroDaRodada
// Saida: -
void GeradorDeRodadas::escreve(Entidade * entidades, int numeroDaRodada){
    // estrutura o nome do arquivo
    string nomeDoArquivoDeSaida = "./tmp/rodada-";
    nomeDoArquivoDeSaida.append(to_string(numeroDaRodada));
    nomeDoArquivoDeSaida.append(".txt");
    
    // abertura de arquivo de saída
    ofstream arquivoDeSaida(nomeDoArquivoDeSaida);
    
    // asserção de abertura de arquivo de saída
    erroAssert(arquivoDeSaida.is_open(), "Arquivo de saída do gerador não foi aberto.");

    // escrita das entidades no arquivo de saída
    for (int i = 0; i < this->numeroDeEntidades; i++){
        if (entidades[i].url == "") {
            break;
        }
        
        arquivoDeSaida << entidades[i].url << " " << entidades[i].numeroDeVisitas << endl;   
        leMemLog( (long int) (&entidades[i].url), sizeof(string), 1);
        leMemLog( (long int) (&entidades[i].numeroDeVisitas), sizeof(int), 1);
    }
    
    // fechamento do arquivo de saída
    arquivoDeSaida.close();
}

bool GeradorDeRodadas::leituraTerminou() {
    return this->terminou;
}