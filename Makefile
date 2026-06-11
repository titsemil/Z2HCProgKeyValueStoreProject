BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc

TARGET := bin/final

FLAGS := -Wall

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

default: $(TARGET)

$(TARGET): $(OBJ)
	gcc $^ -o $@ $(FLAGS)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $^ -o $@ -I$(INC_DIR)

# For debug/understanding
_print:
	@echo $(SRC)
	@echo $(OBJ)

.PHONY: clean
clean:
	rm -f $(BIN_DIR)/*
	rm -f $(OBJ_DIR)/*.o