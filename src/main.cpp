#include <iostream>                 //Biblioteca padrão i/o
#include <locale>                   //Biblioteca com funcionalidades para manipular a localidade 
#include "linha_comando.hpp"        //Importa a classe que lida com os argumentos da linha de comando
#include "processa_arquivo.hpp"     //Importa a classe que lida com o processamento de arquivos de texto no formato UTF-8
//#include "arquivo_saida.hpp"      //importa a classe que lida com o salvamento do resultado do processamento de palavras, feito pela classe ProcessaArquivo
//Aqui foi comentado pois realizamos mudanças para utilizar a classe arquivo_saida no processa_arquivo.cpp

    //Main com int argc e char* argv para recebimento dos parâmetros via linha de comando
int main(int argc, char* argv[]) {
    //Locale foi configurado para suportar caracteres Unicode
    std::locale::global(std::locale(""));  //Define a localidade do sistema para o padrão do SO
    std::wcout.imbue(std::locale(""));     //Configura o wcout para também usar a localidade do SO

    //Chama a classe que lida com argumentos da linha de comando
    LinhaComando cmd(argc, argv);

    //Chama a classe ProcessaArquivo para ler e processar o arquivo de entrada
    ProcessaArquivo ProcessaArq(cmd.GetNome());  //ProcessaArq é um objeto criado a partir da classe ProcessaArquivo

    if (!ProcessaArq.arquivoAbriu()){     //Verifica se o arquivo foi aberto corretamente, caso contrário retorna FALSE
        std::wcerr << L"Erro ao abrir o arquivo!" << std::endl;  //Informa que ocorreu um erro ao tentar abrir o arquivo 
        return 1;               //Encerra o programa com código de errro 1
    }

    //Chama o método realizaContagem da classe ProcessaArq, responsável por realizar a lógica de contagem de palavras, palavras distintas e caracteres
    ProcessaArq.realizaContagem();  //processa_arquivo.cpp

    //Chama o método ordenaPalavras da classe ProcessaArq para ordenar as palavras e gerar o arquivo de saída com base nos parâmetros recebidos por terminal
    ProcessaArq.ordenaPalavras(cmd.GetOrdem(), cmd.GetFormatoSaida()); //processa_arquivo.cpp

    //Exibe as saídas padrão no terminal. 
    ProcessaArq.printaSaidaPadrao(); //processa_arquivo.cpp

    return 0;
}
