CC=gcc -g
CFLAGS=-Wall


debug: CFLAGS += -g

main: bin/main.o bin/tree.o bin/queue.o
	$(CC) $(CFLAGS) -o bin/main bin/main.o bin/tree.o bin/queue.o

bin/main.o: src/main.c bin/tree.o
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o

bin/tree.o: src/tree.c src/tree.h bin/queue.o
	$(CC) $(CFLAGS) -c src/tree.c -o bin/tree.o

bin/queue.o: src/queue.c src/queue.h
	$(CC) $(CFLAGS) -c src/queue.c -o bin/queue.o

clean:
	rm -f bin/*
