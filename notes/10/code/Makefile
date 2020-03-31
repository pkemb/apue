
CC = gcc
LD = ld
CFLAGS = -I../.. -Wall
LDFLAGS = 
LDLIBS =

PROGS += test_signal
PROGS += test_kill
PROGS += test_sleep2

all: ${PROGS} sleep2.o

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

test_sleep2: test_sleep2.o sleep2.o
	$(CC) $(CFLAGS) -o test_sleep2 test_sleep2.o sleep2.o $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
