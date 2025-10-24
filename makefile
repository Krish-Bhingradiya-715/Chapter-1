CC = gcc
CFLAGS = -Wall -g

# List of source files
SOURCES = 1st.c 2nd.c 3rd.c 4th.c 5th.c 6th.c 7th.c 8th.c 9th.c 10th.c 11th.c 12th.c 13th.c 14th.c

# List of executables
EXECS = $(SOURCES:.c=)

all: $(EXECS)

# Files that require math library
MATHFILES = 2nd 5th

# Rule for files that need -lm
$(MATHFILES): %: %.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# Generic rule for other files
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECS) *.o
