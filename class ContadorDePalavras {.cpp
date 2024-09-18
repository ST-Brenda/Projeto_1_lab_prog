class ContadorPalavras {
private:
    map<wstring, int> contagemPalavras;
    int totalCaracteres = 0;
    int totalPalavras = 0;

public:
    void processarArquivo(const wstring& nomeArquivo) {
        wifstream arquivo(nomeArquivo);
        arquivo.imbue(locale(arquivo.getloc(), new codecvt_utf8<wchar_t>));

        if (!arquivo) {
            wcerr << L"Erro ao abrir o arquivo." << endl;
            return;
        }

        wstring palavra;
        wchar_t caractere;

        while (arquivo.get(caractere)) {
            totalCaracteres++;
            if (iswspace(caractere)) {
                if (!palavra.empty()) {
                    palavra = para_minusculo(palavra);  // Função fictícia que converte para minúsculas
                    contagemPalavras[palavra]++;
                    totalPalavras++;
                    palavra.clear();
                }
            } else {
                palavra += caractere;
            }
        }

        if (!palavra.empty()) {
            palavra = para_minusculo(palavra);
            contagemPalavras[palavra]++;
            totalPalavras++;
        }
        arquivo.close();
    }

    map<wstring, int> obterContagemPalavras() { return contagemPalavras; }
    int obterTotalCaracteres() { return totalCaracteres; }
    int obterTotalPalavras() { return totalPalavras; }
};