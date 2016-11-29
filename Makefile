
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS += -Wall -g -std=c++11

all: program

run:
	@./program

clean:
	rm -f program *.o *.d

format:
	clang-format -i --style=webkit $(SRC)

program: $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o : %.cpp
%.o : %.cpp %.d
	$(CXX) $(CXXFLAGS) -MM -MP -MT $@ -o $*.d $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.d: ;
.PRECIOUS: %.d
-include $(patsubst %.cpp,%.d,$(SRC))
