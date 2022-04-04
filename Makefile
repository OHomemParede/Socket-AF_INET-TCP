CC=g++
FLAG=-g -Wall
SRC_PATH=./src
OBJ_PATH=./objects
OBJS=main.o socket_stuff.o

$(shell mkdir $(OBJ_PATH))

%.o: $(SRC_PATH)/%.cpp
	$(CC) $(FLAG) -c $^ -o $(OBJ_PATH)/$@


main: $(OBJS)
	$(CC) $(FLAG) -o main $(OBJ_PATH)/*.o
	chmod 700 main


clean:
	rm -f main
	rm -f $(OBJ_PATH)/*.o
	