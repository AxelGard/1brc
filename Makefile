# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src

# Directories
SRC_DIR = src
BUILD_DIR = build
TARGET = main

# Find all source files in SRC_DIR with .cpp or .cc extensions
SRCS := $(shell find $(SRC_DIR) -type f \( -name '*.cpp' -o -name '*.cc' \))
# Corresponding object files in BUILD_DIR
OBJS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRCS:.cpp=.o))
OBJS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(OBJS:.cc=.o))

# Default target
all: $(BUILD_DIR) $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
