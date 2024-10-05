#ifndef _ARQUIVO_SAIDA_HPP_
#define _ARQUIVO_SAIDA_HPP_

#include <string>
#include <vector>
#include <utility>  //Para usar pair para agrupar valores (wstring e int, no caso)

class ArquivoSaida {
public:
    //Recebe o formato e as palavras
    ArquivoSaida(const std::string& formato_saida, const std::vector<std::pair<std::wstring, int>>& palavras_saida);

    //Função principal para salvar o arquivo no formato informado pelo usuário
    void salva();

private:
    std::string formato_saida;
    std::vector<std::pair<std::wstring, int>> palavras_saida;

    //Funções que permitem salvar em CSV e HTML
    void salvaCSV();
    void salvaHTML();
};

#endif
