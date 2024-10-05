#Nome do executável que será gerado para o programa
EXECUTAVEL = palavras

#Compilador
COMPILADOR = g++

#Flag de compilação que possui algumas otimizações
FLAGS = -O2

#Lista dos arquivos de objetos (gerados a partir dos .cpp)
.O = main.o linha_comando.o processa_arquivo.o arquivo_saida.o

#Regra padrão, gera o executável a partir dos objetos
$(EXECUTAVEL): $(.O)
	$(COMPILADOR) $(FLAGS) -o $(EXECUTAVEL) $(.O)
	@echo ""
	@echo "Compilação executada com sucesso!" 
	@echo "Nome do executável gerado: 'palavras'"
#Mensagem no terminal para informar que a compilação ocorreu com sucesso 

#Compila o main.cpp
main.o: main.cpp linha_comando.hpp processa_arquivo.hpp arquivo_saida.hpp
	$(COMPILADOR) $(FLAGS) -c main.cpp

#Compila o linha_comando.cpp
linha_comando.o: linha_comando.cpp linha_comando.hpp
	$(COMPILADOR) $(FLAGS) -c linha_comando.cpp

#Compila o processa_arquivo.cpp
processa_arquivo.o: processa_arquivo.cpp processa_arquivo.hpp
	$(COMPILADOR) $(FLAGS) -c processa_arquivo.cpp

#Compila o arquivo_saida.cpp
arquivo_saida.o: arquivo_saida.cpp arquivo_saida.hpp
	$(COMPILADOR) $(FLAGS) -c arquivo_saida.cpp

#Apaga os arquivos .o e o executável do programa
clean:
	rm -f *.o $(EXECUTAVEL)
	@echo ""
	@echo "Arquivos .o e executável do programa removidos!"

#Apaga apenas os arquivos de saída gerados
clean_outputs:
	rm -f palavras.html palavras.csv
	@echo ""
	@echo "Arquivos de saída removidos!"