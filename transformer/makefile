# Compiler
CC   = g++
OPTS = -std=c++11
PROJECT = transformer

SRCS = $(shell find ./ -name '*.cpp')
DIRS = $(shell find ./ -type d | sed 's/src/./g' ) 
OBJS = $(patsubst src/%.cpp,out/%.o,$(SRCS))

# Targets
$(PROJECT): clean buildrepo $(OBJS)
	$(CC) $(OPTS) $(OBJS) $(LIBS) $(INCS) -o $@

out/%.o: ./%.cpp
	$(CC) $(OPTS) -c $< $(INCS) -o $@

clean:
	rm $(PROJECT) out -Rf

buildrepo:
	mkdir -p out
	for dir in $(DIRS); do mkdir -p out/$$dir; done