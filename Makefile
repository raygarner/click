CC = gcc
CFLAGS = -O2 -Wall

click: click.c
	$(CC) $(CFLAGS) $? -o $@

clean: click
	$(RM) $?
