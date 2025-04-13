CC = gcc
CFLAGS = -Wall -Wextra -I./include

BUILD_DIR=./bin
BIN = $(BUILD_DIR)/build

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# default target
build: $(BIN)

# linking object files to binary
$(BIN): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJ) -o $@

# compile .c to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
