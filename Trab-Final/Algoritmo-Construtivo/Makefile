# Linux Makefile
# (C) Bruno de Oliveira Schneider - May 2014


APPLICATION = constr-distr.app
CXXFLAGS = -Wall -Wconversion -std=c++14 -O0 -g -pg
LDFLAGS =
LDLIBS =

OBJECTS = constr-distr.o Vertex.o District.o AdjacencyMatrix.o AdjacencyList.o \
          Graph.o file_manager.o math_calc.o

# first, try to compile from this project
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

# second, try to compile from the core
%.o: algorithms/source/%.cpp algorithms/%.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

$(APPLICATION): $(OBJECTS) constr-distr.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f *.o *~ $(APPLICATION)
