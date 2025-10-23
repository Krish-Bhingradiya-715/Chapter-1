CC = gcc
CFLAGS = -Wall -g
SOURCES = ex2.c ex3.c ex4.c ex5.c ex6.c ex7.c ex8.c ex9.c ex10.c ex12.c ex13.c ex14.c ex15.c ex16.c ex17.c ex18.c ex19.c ex20.c ex21.c ex22.c ex23.c ex24.c 
EXECS = $(SOURCES:.c=)

.PHONY: all clean

all: $(EXECS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECS) *.o
