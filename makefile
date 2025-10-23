CC = gcc
CFLAGS = -Wall -g
SOURCES = 2nd.c 3rd.c 4th.c 5th.c 6th.c
EXECS = $(SOURCES:.c=)
all: $(EXECS)
%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f $(EXECS) *.o

