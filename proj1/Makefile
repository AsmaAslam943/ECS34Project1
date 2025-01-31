BIN_DIR = bin
OBJ_DIR = obj
TARGET = $(BIN_DIR)/teststrutils

GTEST_FLAGS = -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread 

SRC = StringUtils.cpp StringUtilsTest.cpp 
OBJ = $(SRC:.cpp=.o)

all: directories $(TARGET) runtests 

StringUtils.o: /users/asmaaslam/ECS34Project1/proj1/include/StringUtils.h ./src/StringUtils.cpp 
	g++ -c -std=c++17 -I /users/asmaaslam/ECS34Project1/proj1/include ./src/StringUtils.cpp 
StringUtilsTest.o: /users/asmaaslam/ECS34Project1/proj1/include/StringUtils.h ./testsrc/StringUtilsTest.cpp
	g++ -c -std=c++17 -I /users/asmaaslam/ECS34Project1/proj1/include ./testsrc/StringUtilsTest.cpp $(GTEST_FLAGS)
$(TARGET): $(OBJ)
		g++ $(OBJ) -o $(TARGET) -std=c++17 $(GTEST_FLAGS) 

runtests: $(TARGET)
		$(TARGET)

directories: 
		mkdir -p $(BIN_DIR)
		mkdir -p $(OBJ_DIR)

clean:
		rm -rf $(BIN_DIR)
		rm -rf $(OBJ_DIR)