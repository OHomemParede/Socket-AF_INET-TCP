CC=g++
FLAG=-g -Wall
SRC_PATH=./src
OBJ_PATH=./objects
OBJS=main.o


%.o: $(SRC_PATH)/%.cpp
	$(shell mkdir $(OBJ_PATH))
	$(CC) $(FLAG) -c $< -o $(OBJ_PATH)/$@


main: $(OBJS)
	$(CC) $(FLAG) -o main $(OBJ_PATH)/$^
	chmod 700 main


clean:
	rm -f main
	rm -f $(OBJ_PATH)/*.o
	