# Linux Makefile
# (C) Bruno de Oliveira Schneider - May 2014


APPLICATION = lista.app
CXXFLAGS = -Wall -Wconversion -std=c++14 -O0 -g -pg
LDFLAGS =
LDLIBS =

OBJECTS = Lista.o ListaDupla.o Noh.o

# first, try to compile from this project
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

# second, try to compile from the core
%.o: structures/source/%.cpp structures/%.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

$(APPLICATION): $(OBJECTS) main.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f *.o *~ $(APPLICATION)
