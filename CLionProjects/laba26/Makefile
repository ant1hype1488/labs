CFLAGS  = -Wall -Werror
files = main.o stack.o
all: app
	rm *.o
	clear
app: $(files)
	gcc $(files) -o app $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

stack.o:stack.c
	gcc -c stack.c $(CFLAGS)
