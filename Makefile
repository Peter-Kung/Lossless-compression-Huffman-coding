CC := gcc
CFLAG := -o
TEST := client.c
OBJ := client

all:
	$(CC)  minheap.c client.c $(CFLAG) $(OBJ)
