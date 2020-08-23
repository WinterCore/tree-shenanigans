CC=gcc -g
CFLAGS=-Wall


debug: CFLAGS += -g
debug: main

main: bin/main.o bin/tree.o bin/queue.o bin/min-heap.o bin/arr-min-heap.o
	$(CC) $(CFLAGS) -o bin/main bin/main.o bin/tree.o bin/queue.o bin/min-heap.o bin/arr-min-heap.o

bin/main.o: src/main.c bin/tree.o bin/min-heap.o bin/queue.o
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o

bin/tree.o: src/tree.c src/tree.h bin/queue.o
	$(CC) $(CFLAGS) -c src/tree.c -o bin/tree.o

bin/queue.o: src/queue.c src/queue.h
	$(CC) $(CFLAGS) -c src/queue.c -o bin/queue.o

bin/min-heap.o: src/min-heap.c src/min-heap.h
	$(CC) $(CFLAGS) -c src/min-heap.c -o bin/min-heap.o

bin/arr-min-heap.o: src/arr-min-heap.c src/arr-min-heap.h
	$(CC) $(CFLAGS) -c src/arr-min-heap.c -o bin/arr-min-heap.o

clean:
	rm -f bin/*
