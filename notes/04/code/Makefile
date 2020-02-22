
CC = gcc
CFLAGS = -I../.. -Wall
LDFLAGS = 
LDLIBS =

PROGS += test_lstat
PROGS += print_argv

all: ${PROGS}

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o test.txt
