CXX = g++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99
LDLIBS = -pthread
# main.cpp
SOURCES = board.cpp player.cpp card.cpp resource.cpp tile.cpp hexagon.cpp catan.cpp Demo.cpp
HEADERS = board.hpp player.hpp card.hpp resource.hpp piece.hpp tile.hpp hexagon.hpp catan.hpp
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLES = catan

all: $(EXECUTABLES)

run: catan
	./$^

# demo: Demo.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

# test: Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

catan: $(OBJECTS) Demo.o
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





# CXX = g++
# CXXFLAGS = -std=c++11 -Werror -Wsign-conversion -pedantic
# VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99
# LDLIBS = -pthread

# SOURCES = demo.cpp catan.cpp board.cpp player.cpp card.cpp resource.cpp piece.cpp
# HEADERS = catan.hpp board.hpp player.hpp card.hpp resource.hpp piece.hpp
# OBJECTS = $(SOURCES:.cpp=.o)

# EXECUTABLES = catan

# all: $(EXECUTABLES)

# run: catan
# 	./$^

# catan: $(OBJECTS) Demo.o
# 	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

# tidy:
# 	clang-tidy $(SOURCES) $(HEADERS) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: $(EXECUTABLES)
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./catan 2>&1 | { egrep "lost| at " || true; }

# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) --compile $< -o $@

# clean:
# 	rm -f *.o $(EXECUTABLES)
