CC=gcc
CFLAGS=-lreadline -I.

cdshell: cdshell.c
	$(CC) -o cdshell cdshell.o -I.

clean:
	/bin/rm -f *.o *~
