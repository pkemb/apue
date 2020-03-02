
CC = gcc
CFLAGS = -I../.. -Wall
LDFLAGS = 
LDLIBS =

PROGS += test_getpid

all: ${PROGS}

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
