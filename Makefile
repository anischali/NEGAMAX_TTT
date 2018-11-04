CC = g++
PROGRAMME = NEGAMAX  
CCFLAGS = -Wall -g
HEADERS = negamax.h 
SOURCES = main.cpp negamax.cpp game.cpp 
OBJ = $(SOURCES:.cpp=.o)
RM=rm 
all: $(PROGRAMME)
$(PROGRAMME):$(OBJ)
	$(CC) $(OBJ) $(CCFLAGS) -o $(PROGRAMME)
%.o: %.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	$(RM) -r ./$(PROGRAMME) ./*~ ./$(OBJ)
