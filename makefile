all: nodeList.o main.o playlist.o
	gcc -o listo nodeList.o main.o playlist.o

main.o: main.c
	gcc -c main.c

nodeList.o: nodeList.c
	gcc -c nodeList.c

playlist.o: playlist.c
	gcc -c playlist.c

run: all
	./listo

clean:
	rm -rf *.o *~ listo

debug: nodeList.o main.o playlist.o
	gcc -o debugo -g nodeList.c main.c playlist.c

valgrind: debug
	valgrind --leak-check=yes ./debugo

gdb: debug
	gdb ./debugo
