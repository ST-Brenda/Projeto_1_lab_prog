#include <iostream>
#include <fstream>   //file stream para ler arquivos 
#include <cctype>   //Biblioteca do C para trabalhar com char
#include <map>

using namespace std;

int main(){
    ifstream arq("gpl.txt");    //input file stream 
    ofstream csv("palavras.csv");

    char ch;
    string palavra;
    map<string, int> ocorrencias; 

    while(arq.get(ch)){   //lê o próximo caractere do arquivo e armazena na variável
        if(isalpha(ch)){    //Testa se é uma letra 
            palavra += tolower(ch);     //Concatena letra minúscula
        }
        else if(palavra.size() > 0){  //Testa se tem algo na palavra
            //cout << palavra << endl;
            ocorrencias[palavra]++; //mesmo que ocorrencias[palavra] = ocorrencias[palavra] +1
            palavra.clear();    //para limpar a palavra a cada iteração, senão sempre concatena
        }
    }

    cout << ocorrencias.size() << " palavras distintas\n";

    csv << "\"Palavra\";\"Número de aparições\"\n";

    for(auto [k, v] : ocorrencias){
        csv << '"' << k << '"' << ';' << v << endl;
    }


}

