CC 	   = gcc
CFLAGS = -Wall -Wextra 
OUT	   = temp_convert

main : src/main.c
	$(CC) $(CFLAGS) src/main.c -o $(OUT)