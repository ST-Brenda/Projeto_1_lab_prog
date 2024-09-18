class ExportadorDados {
public:
    virtual void exportarDados(const vector<pair<wstring, int>>& palavrasOrdenadas) = 0;
};

class ExportadorCSV : public ExportadorDados {
public:
    void exportarDados(const vector<pair<wstring, int>>& palavrasOrdenadas) override {
        wcout << L"Palavra,Contagem" << endl;
        for (const auto& entrada : palavrasOrdenadas) {
            wcout << entrada.first << L"," << entrada.second << endl;
        }
    }
};

class ExportadorHTML : public ExportadorDados {
public:
    void exportarDados(const vector<pair<wstring, int>>& palavrasOrdenadas) override {
        wofstream arquivoHTML(L"saida.html");
        arquivoHTML.imbue(locale(arquivoHTML.getloc(), new codecvt_utf8<wchar_t>));
        arquivoHTML << L"<html><body><table border=\"1\">" << endl;
        arquivoHTML << L"<tr><th>Palavra</th><th>Contagem</th></tr>" << endl;

        for (const auto& entrada : palavrasOrdenadas) {
            arquivoHTML << L"<tr><td>" << entrada.first << L"</td><td>" << entrada.second << L"</td></tr>" << endl;
        }

        arquivoHTML << L"</table></body></html>" << endl;
        arquivoHTML.close();
    }
};
