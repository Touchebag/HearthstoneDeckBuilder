# Compiler options
CC       := g++
CC_FLAGS := -enable-auto-import -Wall
LD_FLAGS := -L $(LIB_DIR)

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
LIB_DIR := lib

# Files
SRC := $(wildcard  $(SRC_DIR)/*.cpp)
INC := $(wildcard  $(INC_DIR)/*.h)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
LIB := $(wildcard  $(LIB_DIR)/*)

# Executable
TARGET := HSDeckBuilder.exe

# Main target
$(TARGET): $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^

# Main source file (no header)
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf $(TARGET) $(OBJ)

# Phony targets
.PHONY: clean
