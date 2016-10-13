BIN := ep3
OBJ := tresReversao.o auxFunctions.o

CC := gcc
CFLAGS := -Wall -pedantic -ansi -O2

#formulas for making binaries

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#general formulas for making objects

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

#general commands for automation

clean:
	rm -rf *.o
