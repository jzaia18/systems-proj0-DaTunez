all: nodeList.o main.o
	gcc -o listo nodeList.o main.o

main.o: main.c
	gcc -c main.c

nodeList.o: nodeList.c
	gcc -c nodeList.c

run: all
	./listo

clean:
	rm -rf *.o listo
