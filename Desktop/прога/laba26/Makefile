all: app

app: main.o  stack_l.o
	gcc main.o  stack_l.o -o app

main.o: main.c
	gcc -c main.c



stack_l.o: stack_l.c
	gcc -c stack_l.c



clean:
	rm -rf *.o hello
