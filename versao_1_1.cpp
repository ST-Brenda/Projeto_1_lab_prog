#include <iostream>      //Biblioteca padrão para input/output
#include <fstream>       //File stream para leitura de arquivos 
#include <cctype>        //Biblioteca do C para trabalhar com char
#include <cstring>       //Para lidar com os argumentos recebidos na linha de comando
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;
//Tem que arrumar isso pra receber o número de aparição de cada palavra
//Implementar
void salvar_em_csv(const vector<pair<string, int>>& palavras) {
    ofstream csv("palavras.csv");
    if (csv.is_open()) {
        for (const auto& palavra : palavras) {
            csv << palavra << endl; //Salva cada palavra em uma nova linha
        }
        csv.close(); //Fecha o arquivo após a gravação
    } 

}

//implementar função para salvar como .html

// 


void salvar_em_html(const vector<pair<string, int>>& palavras) 
{
    ofstream html("palavras.html");

    if (html.is_open()) 
    {
        html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Palavras</title>\n</head>\n<body>\n";
        html << "<h1>Lista de Palavras</h1>\n<ul>\n";

        for (const auto& palavra : palavras) // adiciona as palavras na lista
        { 
            html << "<li>" << palavra << "</li>\n";  //<li> é para listar itens
        }
        html << "</ul>\n</body>\n</html>";
        html.close(); // Fecha o arquivo após a gravação
    }
}


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
    

    //Lê palavras do arquivo
    unordered_map<string, int> palavras;  //unordered_map que armazena as palavras e o número de ocorrências 
    string palavra;
    int num_palavras = 0;
    int num_caracteres = 0;

    while (arq >> palavra) {
        //Transforma todas as letras em minúsculas
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        palavras[palavra]++;
        num_palavras++; //Conta o número total de palavras
        num_caracteres += palavra.size(); //Conta o número total de caracteres
    }
    arq.close(); //Fecha o arquivo



    //PARA ORDENAR AS PALAVRAS:
    vector<pair<string, int>> palavras_vet(palavras.begin(), palavras.end());


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
    
    //PARA ORDENAR AS PALAVRAS EM ORDEM ALFABÉTICA:
    //Ordem alfabética ascendente
    if (ordem == "-ac"){
        sort(palavras_vet.begin(), palavras_vet.end()); 
    } 
    //Ordem alfabética descendente
    else if (ordem == "-ad"){
        sort(palavras_vet.rbegin(), palavras_vet.rend()); 
    }

    //PARA ORDENAR AS PALAVRAS POR NÚMERO DE OCORRÊNCIAS:
    //Ordem crescendente
    else if (ordem == "-nc"){
        sort(palavras_vet.begin(), palavras_vet.end(), [](const auto& a, const auto& b) {
            return a.second < b.second; // Ordena de forma ascendente
        });
    }
    //Ordem descendente
    else if (ordem == "-nd"){
        sort(palavras_vet.begin(), palavras_vet.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Ordena de forma descendente
        });
    } 





    //Define em qual formato de arquivo será exportada a saída do programa
    if(argc > 3){
        formato_arquivo = argv[3];
    }

    //IMPLEMENTAR FUNÇÕES E LÓGICA PARA SALVAR OS ARQUIVOS NO FORMATO SOLICITADO:
    if(formato_arquivo == "-html"){   //Salvar como palavras.html
        cout << "\nSalva como HTML\n";
        salvar_em_html(palavras_vet);
    
    } 
    else{   //Salvar por padrão como palavras.csv 
        cout << "\nSalva como CSV\n";
        salvar_em_csv(palavras_vet);
    }

                                                                                            
    //Mensagem para ver qual a ordem final
    cout << "Ordem: " << ordem << endl;





    //Para teste. Visualizar os argumentos recebidos:
    cout << "\nArgumentos recebidos:\n";
    for (int i = 0; i < argc; ++i) { // Começa de 1 para ignorar o nome do programa
        cout << "Arg " << i << ": " << argv[i] << endl;
    }

    cout << endl;


    //IMPLEMENTAR AS SEGUINTES SAÍDAS SOLICITADAS:
    //Quantidade de caracteres extraídos do arquivo
    //Quantidade de palavras extraídas do arquivo
    //Quantidade de palavras distintas encontradas

    //SAÍDAS PADRÃO SOLICITADAS
    cout << "Total de palavras extraídas do arquivo: " << num_palavras << endl;
    cout << "Total de caracteres extraídos do arquivo: " << num_caracteres << endl;
    cout << "Total de palavras distintas: " << palavras_vet.size() << endl;


    //A PARTE DOS ARGUMENTOS APARENTEMENTE DEU CERTO GALERA 😭🙏🏼 

}


