CXX = g++
CXXFLAGS = -g -Wall
TARGET = main.exe

# 현재 디렉토리와 yebbixClient 디렉토리의 모든 cpp 포함
SRCS = $(wildcard *.cpp) $(wildcard yebbixClient/*.cpp) $(wildcard yebbixDatabase/*.cpp)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o
