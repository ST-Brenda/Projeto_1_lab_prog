#include "linha_comando.hpp"
#include <iostream>

LinhaComando::LinhaComando(int argc, char* argv[]) {
    if (argc < 2) {  //O argumento de índice 0 é sempre o nome do arquivo executável do programa
        std::cerr << "Uso de argumentos: ./palavras <nome_do_arquivo_a_ser_lido> [-ac|-ad|-nc|-nd] [-csv|-html]\n";
        exit(1);
    }

    //Aqui, o argumento de índice 1 sempre vai ser o nome do arquivo a ser lido
    nome_arquivo = argv[1];

    //CASO NÃO SEJAM PASSADOS ARGUMENTOS PELA LINHA DE COMANDO O PROGRAMA UTILIZA OS ARGUMENTOS
    //PADRÃO DEFINIDOS NO linha_comando.hpp

    //Lógica para pegar argumentos lidos do terminal
    if (argc > 2) {
        //Verifica se o segundo argumento é uma opção de ordem
        if (std::string(argv[2]) == "-ac" || std::string(argv[2]) == "-ad" || 
            std::string(argv[2]) == "-nc" || std::string(argv[2]) == "-nd") {
            ordem = argv[2];
        }
        
        //Verifica se o terceiro argumento é um formato de saída
        if (argc > 3 && (std::string(argv[3]) == "-csv" || std::string(argv[3]) == "-html")) {
            formato_saida = argv[3];
        }
    }

    //Aqui trata em caso de apenas o segundo argumento ser passado e ser um formato, ao invés de uma ordem
    if (argc == 3 && (std::string(argv[2]) == "-csv" || std::string(argv[2]) == "-html")) {
        formato_saida = argv[2];
    }
}


//Getters:
//Pega os dados recebidos por parâmetro e manda para onde estes getters forem utilizados:
std::string LinhaComando::GetNome() const {
    return nome_arquivo;
}

std::string LinhaComando::GetOrdem() const {
    return ordem;
}

std::string LinhaComando::GetFormatoSaida() const {
    return formato_saida;
}
