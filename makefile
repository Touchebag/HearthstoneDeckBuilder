# Compiler options
CC       := g++
CC_FLAGS :=
LD_FLAGS :=

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

# Files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

# Executable
TARGET := HSDeckBuilder.exe

# Main target
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Main source file (no header)
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf obj/*

# Phony targets
.PHONY: clean
