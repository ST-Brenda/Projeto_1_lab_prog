#include <iostream>
#include <fstream>      
#include <string>       
#include <algorithm>    
#include <cctype>       

int main() {
    std::ifstream arquivoEntrada("gpl.txt"); 
    std::ofstream arquivoSaida("saida.txt");    

    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de entrada!" << std::endl;
        return 1;
    }

    std::string linha;
    while (std::getline(arquivoEntrada, linha)) {
        
        std::transform(linha.begin(), linha.end(), linha.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        
        
        arquivoSaida << linha << std::endl;
    }

    arquivoEntrada.close(); 
    arquivoSaida.close();   

    std::cout << "Conversao concluida. Veja o arquivo 'saida.txt'." << std::endl;
    
    return 0;
}


//cria um arquivo novo txt como "saida.txt" que é onde vai ser salvo o arquivo glp.txt todo em minusuclo
