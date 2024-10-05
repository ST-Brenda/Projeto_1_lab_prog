#include "processa_arquivo.hpp"
#include "arquivo_saida.hpp" //Inclui o ArquivoSaida para salvar as palavras
#include <iostream>
#include <locale>           //Para configurar a localidade 
#include <cwctype>          //Para manipulação de caracteres wide
#include <algorithm>        //Para uso de sort


//Recebe o nome do aruivo como parâmetro, inicializa os contadores numPalavras e numCaracteres como 0.
ProcessaArquivo::ProcessaArquivo(const std::string& nomeArquivo) : numPalavras{0}, numCaracteres{0}{
    //Abre o arquivo e configura a localidade 
    arquivo.open(nomeArquivo);
    arquivo.imbue(std::locale("pt_BR.UTF-8"));
}


bool ProcessaArquivo::arquivoAbriu() const{
    return arquivo.is_open();    //Tenta abrir o arquivo usando o nome fornecido
}


//Utiliza o método realizaContagem para contar o número de palavras ============================
void ProcessaArquivo::realizaContagem(){
    std::wstring palavra;   //Armazena a palavra atual
    wchar_t ch;             //Armazena o caractere lido na palavra atual   


    while(arquivo.get(ch)){   //Lê caractere por caractere
        if(iswalpha(ch)){     //Verifica se o caractere é alfabético
            palavra += towlower(ch);    //Adiciona o caractere convertido para minúsculo à variável palavra
            numCaracteres++;            //Incrementa o número de caracteres. CONTA SOMENTE OS CARACTERES NUMÉRICOS
        }
        
        else if(!palavra.empty()){    //Se o caractere não for uma letra e a variável palavra não está vazia, então uma palavra foi completada
            palavras[palavra]++;      //Incrementa a chave das palavras do map: unordered_map<std::wstring, int> palavras;
            numPalavras++;            //Incrementa o contador do número de palavras
            palavra.clear();          //Limpa a variável palavra
        }
    }

    //Verifica se ainda existe alguma palavra não processada
    //Assim se o arquivo terminar com uma palavra sem caracteres não alfabéticos após ela ainda vai realizar sua contagem  
    if(!palavra.empty()){   
        palavras[palavra]++;
        numPalavras++;
    }
}


//Retorna um vetor de pares, onde cada par contém uma palavra wstring e sua contagem, int.
std::vector<std::pair<std::wstring, int>> ProcessaArquivo::getPalavras() const{
    //Cria uma instância do std::vector que vai ser preenchida com os elementos do map palavras
    return std::vector<std::pair<std::wstring, int>>(palavras.begin(), palavras.end());
    //O construtor do vetor é chamado com dois iteradores
    //Assim o vetor é inicializado com todos os pares de chave-valor presentes no map palavras.
}

void ProcessaArquivo::ordenaPalavras(const std::string& ordem, const std::string& formato){
    //Obtém a lista de palavras e suas contagens
    auto palavrasVector = getPalavras();

    //Para ordenar com base na ordem especificada
    if(ordem == "-ac") {
        //Ordem alfabética crescente
        std::sort(palavrasVector.begin(), palavrasVector.end(), [](const auto& a, const auto& b){
            return a.first < b.first; // Compara as palavras
        });
    } 
    
    else if(ordem == "-ad") {
        //Ordem alfabética decrescente
        std::sort(palavrasVector.begin(), palavrasVector.end(), [](const auto& a, const auto& b){
            return a.first > b.first; //Compara as palavras
        });
    } 
    
    else if(ordem == "-nc") {
        //Ordem crescente por número de ocorrências
        std::sort(palavrasVector.begin(), palavrasVector.end(), [](const auto& a, const auto& b){
            return a.second < b.second; //Ordena de forma ascendente
        });
    } 
    
    else if(ordem == "-nd") {
        //Ordem decrescente por número de ocorrências
        std::sort(palavrasVector.begin(), palavrasVector.end(), [](const auto& a, const auto& b){
            return a.second > b.second; //Ordena de forma descendente
        });
    }

    //Cria uma instância de ArquivoSaida e salva as palavras, passando o formato em que será salvo o arquivo e o vetor
    ArquivoSaida ArquivoSaida(formato, palavrasVector);
    ArquivoSaida.salva(); //Salva as palavras no formato especificado
    //Função implementada no arquivo_saida.cpp
}

//Usa um método da classe ProcessaArquivo para printar as saídas padrão no terminal
void ProcessaArquivo::printaSaidaPadrao() const {
    std::wcout << L"Total de palavras extraídas: " << numPalavras << std::endl;
    std::wcout << L"Total de palavras distintas: " << palavras.size() << std::endl;
    std::wcout << L"Total de caracteres extraídos: " << numCaracteres << std::endl;
}