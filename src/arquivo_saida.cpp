#include "arquivo_saida.hpp"
#include <fstream>
#include <locale>

//Construtor da classe ArquivoSaida
ArquivoSaida::ArquivoSaida(const std::string& formato, const std::vector<std::pair<std::wstring, int>>& palavras) : formato_saida(formato), palavras_saida(palavras) {}
//Inicializa as variáveis formato e palavras com os valores fornecidos no construtor.


//Função que define qual o formato de arquivo a ser exportado:
void ArquivoSaida::salva() {
    if(formato_saida == "-html"){
        salvaHTML();  //Salva em .HTML
    }

    else{
        salvaCSV();   // Salvar em .CSV (padrão)
    }
}

//Função para salvar o arquivo no formato CSV
void ArquivoSaida::salvaCSV(){
    std::wofstream csv("palavras.csv");
    csv.imbue(std::locale("pt_BR.UTF-8")); // Configura para UTF-8
    if(csv.is_open()){
        csv << L"\"Palavra\";\"Número de aparições\"\n";
        for (const auto& [k, v] : palavras_saida){
            csv << L'"' << k << L'"' << L';' << v << std::endl; //Salva a palavra e o seu respectivo número de ocorrências
        }
        csv.close(); //Fecha o arquivo após a gravação
    }
}

//Função para salvar o arquivo no formato .HTML
void ArquivoSaida::salvaHTML() {
    std::wofstream html("palavras.html");
    html.imbue(std::locale("pt_BR.UTF-8")); //Configura para UTF-8
    if (html.is_open()) {
        html << L"<!DOCTYPE html>\n<html>\n<head>\n<title>Palavras</title>\n</head>\n<body>\n";
        html << L"<center><h1>Lista de Palavras</h1></center>\n<center><table border='5'>\n";

        //Cabeçalho da tabela
        html << L"<tr>\n<th>Palavra</th>\n<th>Número de aparições</th>\n</tr>\n";

        //Salva a palavra e o seu respectivo número de ocorrências
        for (const auto& palavra : palavras_saida) {
            html << L"<tr>\n<td>" << palavra.first << L"</td>\n<td>" << palavra.second << L"</td>\n</tr>\n";
        }

        html << L"</table></center>\n</body>\n</html>";
        html.close(); //Fecha o arquivo após a gravação
    }
}
