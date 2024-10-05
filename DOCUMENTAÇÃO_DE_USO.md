# Documentação de uso do programa 'Contador de Palavras 2.0'

Documentação de uso do programa feito para o primeiro projeto da disciplina de **Laboratório de Programação III**, intitulado **Contador de Palavras 2.0**.

## Objetivos:

**Os objetivos do programa são:**

- **Suporte a Unicode:** Permitir a leitura de arquivos com caracteres Unicode, facilitando a manipulação de textos em diferentes idiomas;
- **Contagem de Palavras:** Realizar a contagem de palavras totais e palavras distintas presentes no arquivo fornecido;
- **Ordenação Personalizada:** Realizar a ordenação das palavras com base nas preferências do usuário;
- **Exportação Flexível:** Exportar as palavras ordenadas e seu número de ocorências para um arquivo com formato selecionado pelo usuário, podendo ser `.cvs` ou `.html`.  

## Pré-requisitos:

### Certifique-se de possuir os itens a seguir:

- **GIT instalado e configurado** - Para clonar o repositório.
- **Compilador C++** - Para compilar o código-fonte.
- **Ambiente de linha de comando** - Para executar comandos via terminal.
- **Comando `make`** - Para compilação do projeto.

## Para Compilar o Projeto:

1. **Realize um clone do repositório e mude para a pasta 'Projeto_1_lab_prog':**
```bash
git clone git@github.com:ST-Brenda/Projeto_1_lab_prog.git
cd Projeto_1_lab_prog
```

2. **Entre na pasta "src", onde se encontram os códigos fonte do projeto:**
```bash
cd src/
```

3. **Execute o comando para realizar a compilação do programa:**
```bash
make
```


### Os parâmetros aceitos são os seguintes:

#### Parâmetros referentes à ordenação das palavras:
- `-ac`: Ordem alfabética ascendente da palavra (padrão).
- `-ad`: Ordem alfabética descendente da palavra.
- `-nc`: Ordem ascendente do número de ocorrências.
- `-nd`: Ordem descendente do número de ocorrências.

#### Parâmetros referentes ao formato do arquivo de saída:
- `-csv`: Exporta as palavras para um arquivo CSV (Comma-separated values) (default).
- `-html`: Exporta as palavras para um arquivo HTML, apresentando os resultados em uma tabela `<TABLE>`.


## Utilização:

Após seguir os passos acima, será gerado um executável, de nome `palavras`, que será responsável por realizar a contagem e ordenação das palavras em um arquivo de texto.

Para execução do programa, abra o terminal no diretório em que se encontra este executável e digite o seguinte comando:

```bash
./palavras <arquivo_texto_a_ser_lido> [-ac|-ad|-nc|-nd] [-csv|-html]
```

- <arquivo_texto_a_ser_lido>: Arquivo de texto que deseja processar.

- [-ac|-ad|-nc|-nd]: Critério de ordenação das palavras.

- [-csv|-html]: Formato desejado do arquivo de saída.

**Exemplo de uso:**
```bash
./palavras texto.txt -nc -html
```

**Caso não seja informado algum destes parâmetros, o programa utilizará os definidos como padrão, sendo eles '-ac' e '-csv'**

## Saídas:

### Possíveis mensagens de erro:
- `bash: ./palav: Arquivo ou diretório inexistente`

Indica que o nome do executável foi informado incorretamente. Neste caso, `./palav` ao invés de `./palavras`.

- `Uso: ./palavras <nome_do_arquivo_a_ser_lido> [-ac|-ad|-nc|-nd] [-csv|-html]`

Indica que o arquivo de texto a ser lido não foi informado.


- `Erro ao abrir o arquivo!`

Indica que o arquivo de texto não foi encontrado. Possíveis causas são erro no nome do arquivo ou a não existência do mesmo. 

### Terminal:
Ao fim da execussão serão exibidas as seguintes saídas no terminal:
- Total de palavras extraídas
- Total de palavras distintas 
- Total de caracteres extraídos

### Arquivo de saída:
Será gerado um arquivo de saída com nome `palavras.csv` ou `palavras.html` dependendo do formato selecionado pelo usuário.

Este arquivo irá conter as palavras ordenadas, também com base nas escolhas do usuário.

## Exclusão dos arquivos .o e do executável:
Caso o usuário deseje realizar a exclusão dos arquivos de objeto e do executável do programa basta executar no diretório destes arquivos o seguinte comando:
```bash
make clean
```

## Exclusão dos arquivos de saída .csv e .html:
Caso o usuário deseje remover somente os arquivos de saída gerados, ele pode fazer isso através do seguinte comando:
```bash
make clean_outputs
```