# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iheaders

# Directories
SRC_DIR = src
BUILD_DIR = build
HEADER_DIR = headers

# Find all .cpp files in the src directory and subdirectories
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output binary
TARGET = $(BUILD_DIR)/Main

# Default rule to build the project
all: $(TARGET)

# Rule to link the object files and create the binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile each source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run the executable
run: $(TARGET)
	@./$(TARGET)

# Phony targets
.PHONY: all clean