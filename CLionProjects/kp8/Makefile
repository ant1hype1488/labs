CFLAGS  = -Wall -Werror
files = main.o list.o
all: app
	rm *.o
	clear
app: $(files)
	gcc $(files) -o app $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

list.o:list.c
	gcc -c list.c $(CFLAGS)
