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

    //CHAMADA DOS MÉTODOS DAS DEMAIS CLASSES:

    return 0;
}
