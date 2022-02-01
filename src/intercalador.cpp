//---------------------------------------------------------------------
// Arquivo	: intercalador.cpp
// Conteudo	: implementacao do intercalador 
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-18 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "intercalador.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

using namespace std;

// Construtor do intercalador 
Intercalador::Intercalador(int numeroDeEntidades, int numeroDeFitas, string nomeArquivoSaida){
    this->numeroDeEntidades = numeroDeEntidades;
    this->numeroDeFitas = numeroDeFitas;
    this->nomeArquivoSaida = nomeArquivoSaida;

    int tamanhoMaximoHeap = numeroDeEntidades * numeroDeFitas;
    // constroi o heap com o tamanho maximo definido pelos parâmetros do programa
    this->heapDeEntidades = Heap(tamanhoMaximoHeap);
    
}

// Descricao: método que intercala as fitas geradas anteriormente e imprime em um arquivo de saída
// Entrada: vetorDeArquivos
// Saida: -
void Intercalador::intercala(ifstream vetorDeArquivos[]){
    // abertura do arquivo de saída
    ofstream arquivoDeSaida(nomeArquivoSaida);
    // asserção de abertura do arquivo de saída
    erroAssert(arquivoDeSaida.is_open(), "Arquivo de saída não foi aberto pelo Intercalador.");

    // leitura e adição no heap da primeira entidade de cada arquivo
    for (int i = 0; i < numeroDeFitas; i++){
        string url;
        unsigned long numeroDeVisitas;

        vetorDeArquivos[i] >> url >> numeroDeVisitas;
        Entidade aux;

        aux.url = url;
        escreveMemLog( (long int) (&aux.url), sizeof(string), 3);
        aux.numeroDeVisitas = numeroDeVisitas;
        escreveMemLog( (long int) (&aux.numeroDeVisitas), sizeof(unsigned long), 3);
        aux.numeroDaFita = i + 1;
        escreveMemLog( (long int) (&aux.numeroDaFita), sizeof(int), 3);
        
        heapDeEntidades.adiciona(aux);
    }

    // remove e imprime o elemento do topo do heap e adiciona no heap a maior entidade originária do mesmo arquivo 
    while (heapDeEntidades.getNumeroDeEntidades() > 0) {
        // remove a entidade do topo do heap
        Entidade aux = heapDeEntidades.remove();
        escreveMemLog( (long int) (&aux), sizeof(Entidade), 3);

        // escreve no arquivo de saída a entidade removida
        arquivoDeSaida << aux.url << " " << aux.numeroDeVisitas << endl;
        leMemLog( (long int) (&aux.url), sizeof(string), 3);
        leMemLog( (long int) (&aux.numeroDeVisitas), sizeof(int), 3);
        int origemDaEntidade = aux.numeroDaFita - 1;
        
        string url;
        unsigned long numeroDeVisitas;

        // lê o próximo elemento do arquivo da entidade removida do heap 
        vetorDeArquivos[origemDaEntidade] >> url >> numeroDeVisitas;
        if (!vetorDeArquivos[origemDaEntidade].eof()){
            Entidade aux;

            aux.url = url;
            escreveMemLog( (long int) (&aux.url), sizeof(string), 3);

            aux.numeroDeVisitas = numeroDeVisitas;
            escreveMemLog( (long int) (&aux.numeroDeVisitas), sizeof(unsigned long), 3);

            aux.numeroDaFita = origemDaEntidade + 1;
            escreveMemLog( (long int) (&aux.numeroDaFita), sizeof(int), 3);
            
            // adiciona no heap a entidade lida
            heapDeEntidades.adiciona(aux);
        }
        
    }

    // desaloca o espaço alocado para o heap na memória secundária
    heapDeEntidades.desaloca();
}