CC = gcc
CFLAGS = -Wall -g
SOURCES = 1st.c 2nd.c 3rd.c 4th.c 5th.c 6th.c 7th.c 8th.c 9th.c 10th.c
EXECS = $(SOURCES:.c=)

.PHONY: all clean

all: $(EXECS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECS) *.o

