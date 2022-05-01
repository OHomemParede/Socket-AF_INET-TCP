CC=gcc
FLAG=-g -Wall

$(shell mkdir $(OBJ_PATH))

main:
	$(CC) $(FLAG) -c src/main.c -o objects/main.o
	$(CC) $(FLAG) -c src/socket_wrappers/socket_wrappers.c objects/socket_wrappers.o
	$(CC) $(FLAG) -c src/utils/utils.c objects/utils.o

	$(CC) $(FLAG) -o main objects/*.o
	chmod 700 main


clean:
	rm -f main
	rm -f objects/*.o
	