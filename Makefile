CC=gcc
CFLAGS= -g -Wall
DFLAGS=
PROGS= main

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f $(PROGS) *.o ~*
