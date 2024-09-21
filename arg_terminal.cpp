#include <iostream>      //Biblioteca padrão para input/output
#include <fstream>       //File stream para leitura de arquivos 
#include <cctype>        //Biblioteca do C para trabalhar com char
#include <cstring>       //Para lidar com os argumentos recebidos na linha de comando


using namespace std;

int main(int argc, char* argv[]){

    //DEFININDO OS ARGUMENTOS PADRÃO:
    string ordem = "-ac";  //Saída em ordem alfabética ascendente como padrão
    string formato_arquivo = "-csv"; //Arquivo de saída em um .csv

    if(argc < 2){    //O argumento de índice 0 é sempre o nome do arquivo executável do programa
    cout << "\nUso de argumentos: " << argv[0] << " <nome_do_arquivo_a_ser_lido> [-ac|-ad|-nc|-nd] [-csv|-html]\n";
        return 1;
    }

    ifstream arq(argv[1]);   //O argumento de índice 1 nesse caso é o nome do arquivo a ser lido
    if(!arq.is_open()){     //Aqui é para caso ocorra algum erro ao tentar abrir o arquivo
        cerr << "Ocorreu um erro ao abrir o arquivo " << argv[1] << endl;
        return 1;
    }

    //AQUI TRATA EM CASO DE NÃO SER INFORMADO O ARGUMENTO DA ORDEM, DEFININDO argv[2] COMO O FORMATO DO ARQUIVO
    //Define em qual ordem serão exibidas as palavras 
    if(argc > 2){
        if(argc > 2 && (argv[2] == string("-ac") || argv[2] == string("-ad") || 
                 argv[2] == string("-nc") || argv[2] == string("-nd"))) {
            ordem = argv[2];    
        }    

        if(argc > 2 && (argv[2] == string("-html"))){
            formato_arquivo = argv[2];    
        }    

    }
    
    //Define em qual formato de arquivo será exportada a saída do programa
    if(argc > 3){
        formato_arquivo = argv[3];
    }




    //IMPLEMENTAR FUNÇÕES E LÓGICA PARA SALVAR OS ARQUIVOS NO FORMATO SOLICITADO:
    if(formato_arquivo == "-html"){   //Salvar como palavras.html
        cout << "\nSalva como HTML\n";
    } 
    else{   //Salvar por padrão como palavras.csv 
        cout << "\nSalva como CSV\n";
    }


    //Mensagem para ver qual a ordem final
    cout << "Ordem: " << ordem << endl;


    //IMPLEMENTAR AS SEGUINTES SAÍDAS SOLICITADAS:
    //Quantidade de caracteres extraídos do arquivo
    //Quantidade de palavras extraídas do arquivo
    //Quantidade de palavras distintas encontradas



    //Para teste. Visualizar os argumentos recebidos:
    cout << "\nArgumentos recebidos:\n";
    for (int i = 0; i < argc; ++i) { // Começa de 1 para ignorar o nome do programa
        cout << "Arg " << i << ": " << argv[i] << endl;
    }


    //ESS PARTE APARENTEMENTE DEU CERTO GALERA 😭🙏🏼 

}


