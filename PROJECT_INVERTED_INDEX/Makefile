OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
P.exe: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o *.exe
