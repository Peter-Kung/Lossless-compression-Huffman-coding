CC := gcc
CFLAG := -g -o
TEST := client.c
OBJ := client
SRC := huffmancode.c minheap.c client.c 
PUSH_TEST := minheap.c push_client.c
POP_TEST := minheap.c pop_client.c
MINHEAP_TEST :=  minheap.c


all:
	$(CC)  $(SRC) $(CFLAG) $(OBJ)

push_test:
	$(CC)  $(PUSH_TEST) $(CFLAG) $(OBJ)

pop_test:
	$(CC) $(POP_TEST) $(CFLAG) $(OBJ)

make_client:
	$(CC)  $(MINHEAP_TEST) $(CFLAG) $(OBJ)
