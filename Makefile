# 1. Compiler and Flags
CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I.
TARGET   := main

# 2. Source Files
# 'wildcard' automatically finds all .cpp files in models/ and the root main.cpp
SRCS     := main.cpp $(wildcard models/*.cpp)

# 3. Object Files
# Replaces .cpp extensions with .o for the list of object files
OBJS     := $(SRCS:.cpp=.o)

# 4. Default Target
all: $(TARGET)

# 5. Link Step
# Creates the executable from the object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 6. Compile Step
# Compiles each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 7. Clean Up
# Removes executable and object files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean