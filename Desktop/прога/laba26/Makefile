CFLAGS  = -Wall -Werror

all: app
	rm *.o 
app: main.o stack.o
	gcc main.o stack.o -o app $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

stack.o:stack.c
	gcc -c stack.c $(CFLAGS)
