CC=gcc
FLAG=-g -Wall

$(shell mkdir $(OBJ_PATH))

main:
	$(CC) $(FLAG) -c src/main.c -o objects/main.o
	$(CC) $(FLAG) -c src/socket_wrappers/socket_wrappers.c -o objects/socket_wrappers.o
	$(CC) $(FLAG) -c src/utils/utils.c -o objects/utils.o
	$(CC) $(FLAG) -c src/server/server.c -o objects/server.o
	$(CC) $(FLAG) -c src/client/client.c -o objects/client.o

	$(CC) $(FLAG) -o main.out objects/*.o
	chmod 700 main.out


clean:
	rm -f main
	rm -f objects/*.o
	