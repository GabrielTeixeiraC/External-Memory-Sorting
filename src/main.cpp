//---------------------------------------------------------------------
// Arquivo	: main.cpp
// Conteudo	: implementacao da função principal do programa
// Autor	: Gabriel Teixeira Carvalho (gabrielteixeirac@dcc.ufmg.br)
// Historico	: 2022-01-13 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "msgassert.hpp"
#include "geradorderodadas.hpp"
#include "intercalador.hpp"
using namespace std;

// Descricao: programa principal para ordenação
// Entrada: argc e argv
// Saida: depende da operacao escolhida
int main(int argc, char* argv[]){
    erroAssert(argc == 5, "Número de argumentos errado.");

    // argv[1] = caminho do arquivo de entrada passado como parametro pela linha de comando
    string nomeArquivoEntrada = argv[1];
    erroAssert(nomeArquivoEntrada.size() > 0, "Nome do arquivo de entrada inválido.");
    
    // argv[2] = caminho do arquivo de saida passado como parametro pela linha de comando
    string nomeArquivoSaida = argv[2];
    erroAssert(nomeArquivoSaida.size() > 0, "Nome do arquivo de saída inválido.");
    
    // argv[3] = número de entidades que podem ser carregadas para a memória primária
    unsigned long numeroDeEntidades = stoul(argv[3]);
    erroAssert(numeroDeEntidades > 0, "O número de entidades deve ser maior que 0.");
    
    // argv[4] = número de fitas a serem intercaladas
    unsigned long numeroDeFitas = stoul(argv[4]);
    erroAssert(numeroDeFitas > 0, "O número de fitas deve ser maior que 0.");
    
    // instanciação do objeto gerador
    GeradorDeRodadas gerador = GeradorDeRodadas(numeroDeEntidades);

    // abertura do arquivo de entrada
    ifstream arquivoDeEntrada(nomeArquivoEntrada);
    erroAssert(arquivoDeEntrada.is_open(), "Arquivo de entrada não foi aberto.");    

    // vetor de entidades passado para os métodos do gerador
    Entidade entidades[numeroDeEntidades];
    
    // leitura, ordenação e escrita das rodadas (fitas)
    for (unsigned long i = 0; i < numeroDeFitas; i++){
        gerador.leEntidades(entidades, arquivoDeEntrada);
        gerador.ordena(entidades);
        gerador.escreve(entidades, i + 1);        
    }
  
    // fechamento do arquivo de entrada
    arquivoDeEntrada.close();
    
    // instanciação do objeto intercalador
    Intercalador intercalador = Intercalador(numeroDeEntidades, numeroDeFitas, nomeArquivoSaida);
    
    // vetor de arquivos de fitas
    ifstream arquivosDasFitas[numeroDeFitas];

    // abertura dos arquivos das fitas
    for (unsigned long i = 0; i < numeroDeFitas; i++){
        // estruturação do nome do arquivo
        string nomeDoArquivo = "./tmp/rodada-";
        nomeDoArquivo.append(to_string(i + 1));
        nomeDoArquivo.append(".txt");

        // abertura do arquivo
        arquivosDasFitas[i].open(nomeDoArquivo);
        
        // asserção de abertura do arquivo
        erroAssert(arquivosDasFitas[i].is_open(), "Arquivo de fita não foi aberto.");
    }

    // método que intercala as fitas
    intercalador.intercala(arquivosDasFitas);
    
    // fechamento dos arquivos das fitas
    for (unsigned long i = 0; i < numeroDeFitas; i++){
        arquivosDasFitas[i].close();
    }
    
    return 0;
}