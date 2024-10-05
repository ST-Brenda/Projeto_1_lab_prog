#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main(){

    std::map<std::string, int > cont;
    std::string filename = "gpl.txt";

   std::ifstream file(filename); 
   if (!file.is_open())
    {
        std::cerr<<"Erro ao tentar abrir o arquivo!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream iss(line);
        std::string word;

        while (iss >> word)
        {
            ++cont[word];
        }
         
    }

    std::cout << "\n Frequência de palavras encntradas:\n";
    for (const auto& pair: cont)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;

}
