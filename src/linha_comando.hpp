#ifndef _LINHA_COMANDO_HPP_
#define _LINHA_COMANDO_HPP_

#include <string>

class LinhaComando {
private:
    std::string nome_arquivo;
    //Inicializa os parâmetros com valores padrão
    std::string ordem = "-ac"; //Padrão para ordem
    std::string formato_saida = "-csv"; //Padrão para formato
   
public:
    LinhaComando(int argc, char* argv[]);
    //Usados na main:
    std::string GetNome() const;
    std::string GetOrdem() const;
    std::string GetFormatoSaida() const;
};

#endif
