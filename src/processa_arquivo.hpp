#ifndef _PROCESSA_ARQUIVO_HPP_
#define _PROCESSA_ARQUIVO_HPP_

#include <unordered_map>  //optamos por uso do unordered_map pois foram implementadas as funções de ordenação
#include <vector>
#include <string>
#include <fstream>        //para uso de wifstream (com caracteres wide)
#include <algorithm>      //Para uso de sort

class ProcessaArquivo {
private:
    std::unordered_map<std::wstring, int> palavras;
    std::wstring nomeArquivo;
    std::wifstream arquivo;
    int numPalavras;
    int numCaracteres;

public:
    ProcessaArquivo(const std::string& nomeArquivo);
    bool arquivoAbriu() const;
    void realizaContagem();
    std::vector<std::pair<std::wstring, int>> getPalavras() const;
    void printaSaidaPadrao() const;
    //Aqui passa para o método
    void ordenaPalavras(const std::string& ordem, const std::string& formato);
};

#endif
