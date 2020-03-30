
CC = gcc
CFLAGS = -I../.. -Wall
LDFLAGS = 
LDLIBS =

PROGS += test_signal
PROGS += test_kill

all: ${PROGS}

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
