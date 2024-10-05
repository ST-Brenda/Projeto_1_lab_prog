# Primeiro Projeto - Laboratório de Programação III  

**Professor:** Marcos José Brusso    
**Integrantes do grupo:**    
- Brenda Slongo Taca    
- Felipe Borges da Silva    
- Gabriel Schumann Vieira     

## Objetivo  

Criar uma nova versão do programa `palavras.cpp` elaborado na aula de 29/08 que realiza contagem de palavras distintas contidas em um arquivo-texto de entrada. A versão deve atender aos seguintes requisitos:  

### Requisitos 
1. **Aceitar arquivos Unicode** em vez de ASCII.  
2. **Aceitar o nome do arquivo** na linha de comando (usando `argc`/`argv`).  
3. **Aceitar a ordem em que os dados devem ser apresentados** na saída como chave de linha de comando:  
   - `-ac`: Ordem alfabética ascendente da palavra (default).  
   - `-ad`: Ordem alfabética descendente da palavra.  
   - `-nc`: Ordem ascendente do número de ocorrências.  
   - `-nd`: Ordem descendente do número de ocorrências.  
4. **Selecionar o formato da saída** também com chave de linha de comando:  
   - `-csv`: Formato CSV (Comma-separated values) (default).  
   - `-html`: Exportar dados para um arquivo HTML, apresentando os resultados em uma tabela `<TABLE>`.  
   
### Saída padrão  
Ao final da execução, apresentar na saída padrão:  
- A quantidade de caracteres extraídos do arquivo.  
- A quantidade de palavras extraídas do arquivo.  
- A quantidade de palavras distintas encontradas.  
