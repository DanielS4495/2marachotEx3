CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = catan
SOURCES = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
    rm -f $(TARGET)
