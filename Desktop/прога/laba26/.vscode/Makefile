HEADERS = stack_array.h 
OBJECTS = main.o stack_array.o
 
default: main.exe
 
%.o: %.c $(HEADERS)
    gcc -c $< -o $@
 
program: $(OBJECTS)
    gcc $(OBJECTS) -o $@
 
clean:
    -rm -f $(OBJECTS) *.exe