CC = gcc
CFLAGS = -lreadline -std=c11 -I.

cdshell: cdshell.o
	$(CC) -lreadline -o cdshell cdshell.o -I.

clean:
	/bin/rm -f *.o *~
