CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++17

TARGET = simulator

SRCS = src/main.cpp src/simulation.cpp src/analysis.cpp src/rules.cpp src/matrix.cpp src/data.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
