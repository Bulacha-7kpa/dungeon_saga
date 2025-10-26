# Nome do Executável final
TARGET = build/dg_saga

# Flags de compilação
CFLAGS = -Wall -Wextra -Ilibs/SDL2/include -Iinclude 
LDFLAGS = -Llibs/SDL2/lib -Llibs/SDL2_mixer/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer
# Arquivos .c do projeto
SRC = src/main.c src/player.c src/utils.c src/item_node.c src/map.c

# Substituindo cada arquivo .c na pasta src por arquivos .o na pasta build 
OBJ = $(SRC:src/%.c=build/%.o)

# -----------------------------
# Regras
# -----------------------------

# Regra padrão: compilar tudo
all: $(TARGET)
	
# Como criar o executável a partir dos .o
$(TARGET): $(OBJ)
	gcc $(OBJ) -o $(TARGET) $(LDFLAGS) 

# Como compilar cada .c em .o
build/%.o: src/%.c
	@if not exist build mkdir build
	gcc $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rmdir /s /q build
