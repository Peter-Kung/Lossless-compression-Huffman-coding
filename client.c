#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include <time.h>

int main()
{
	
	srand(time(NULL));
	
	TreeNode_t *heap;
	int index = 10;
	heap = createMinHeap(index);
	int tail = 0;

	TreeNode_t nodea, nodeb, nodec, noded;
	nodea.alphabet = 'A';
	nodea.quntity = 1;
	nodeb.alphabet = 'B';
	nodeb.quntity = 2;
	nodec.alphabet = 'C';
	nodec.quntity = 3;
	noded.alphabet = 'D';
	noded.quntity = 4;

	push(heap, nodea, &tail);
	push(heap, nodeb, &tail);
	push(heap, nodec, &tail);
	push(heap, noded, &tail);

	pop(heap, &tail);
	for (int i = 1;i <= tail;++i) {
		printf("%c: %d\n", heap[i].alphabet, heap[i].quntity);
	}
	puts("");

	pop(heap, &tail);
	for (int i = 1;i <= tail;++i) {
		printf("%c: %d\n", heap[i].alphabet, heap[i].quntity);
	}
	puts("");
	pop(heap, &tail);
	for (int i = 1;i <= tail;++i) {
		printf("%c: %d\n", heap[i].alphabet, heap[i].quntity);
	}
	puts("");
	return 0;
}

