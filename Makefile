# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
BUILD_DIR = build
BIN_DIR = bin

# User must provide a source directory
SRC ?=

# Target name = same as source directory name (basename)
TARGET = $(BIN_DIR)/$(notdir $(SRC))

# Find sources inside chosen SRC dir
SRCS := $(wildcard $(SRC)/*.cpp $(SRC)/*.cc)
OBJS := $(patsubst $(SRC)/%, $(BUILD_DIR)/$(notdir $(SRC))/%,$(SRCS:.cpp=.o))
OBJS := $(patsubst $(SRC)/%, $(BUILD_DIR)/$(notdir $(SRC))/%,$(OBJS:.cc=.o))

# Default target
all: $(TARGET)

# Link final binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/$(notdir $(SRC))/%.o: $(SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(SRC) -c $< -o $@

$(BUILD_DIR)/$(notdir $(SRC))/%.o: $(SRC)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(SRC) -c $< -o $@

# Clean everything generated
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

