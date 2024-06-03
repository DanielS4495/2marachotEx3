CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99
LDLIBS = -pthread
# main.cpp
SOURCES = player.cpp card.cpp resource.cpp board.cpp piece.cpp Demo.cpp
HEADERS = player.hpp  card.hpp resource.hpp board.hpp piece.hpp
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLES = demo test catan

all: $(EXECUTABLES)

run: catan
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

# test: Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

catan: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)
	./$@

tidy:
	clang-tidy $(SOURCES) $(HEADERS) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: $(EXECUTABLES)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./catan 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o $(EXECUTABLES)
