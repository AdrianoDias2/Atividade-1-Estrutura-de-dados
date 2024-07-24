# Nome do compilador
CC = gcc

# Opções do compilador
CFLAGS = -Wall -Wextra -Werror -g

# Arquivo de saída
TARGET = main

# Lista de arquivos de origem
SRCS = main.c

# Gera uma lista de arquivos objeto
OBJS = $(SRCS:.c=.o)

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXEC_EXT = .exe
else
    RM = rm -f
    EXEC_EXT =
endif

# Regra padrão, gera o executável
$(TARGET)$(EXEC_EXT): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET)$(EXEC_EXT) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	$(RM) $(OBJS) $(TARGET)$(EXEC_EXT)

# Regra para recompilar tudo do zero
rebuild: clean $(TARGET)$(EXEC_EXT)

# Regra para executar o programa
run: $(TARGET)$(EXEC_EXT)
	./$(TARGET)$(EXEC_EXT)
