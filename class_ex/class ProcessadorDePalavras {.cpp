class ProcessadorPalavras {
private:
    ContadorPalavras contadorPalavras;
    ExportadorDados* exportador;

public:
    ProcessadorPalavras(ExportadorDados* exportador) : exportador(exportador) {}

    void processar(const wstring& nomeArquivo) {
        contadorPalavras.processarArquivo(nomeArquivo);
        auto contagemPalavras = contadorPalavras.obterContagemPalavras();

        vector<pair<wstring, int>> palavrasOrdenadas(contagemPalavras.begin(), contagemPalavras.end());

        sort(palavrasOrdenadas.begin(), palavrasOrdenadas.end(), [](const pair<wstring, int>& a, const pair<wstring, int>& b) {
            return a.first < b.first;
        });

        exportador->exportarDados(palavrasOrdenadas);

        // Exibir resumo
        wcout << L"Total de caracteres: " << contadorPalavras.obterTotalCaracteres() << endl;
        wcout << L"Total de palavras: " << contadorPalavras.obterTotalPalavras() << endl;
        wcout << L"Total de palavras distintas: " << contagemPalavras.size() << endl;
    }
};