#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include <time.h>

int main()
{
	
	srand(time(NULL));
	
	TreeNode_t *heap;
	int index = rand() % 10 + 1;
	heap = createMinHeap(index);
	int tail = 0;

	for (int i = 0;i < index;i++) {
		TreeNode_t node;
		node.alphabet = 'A' + i;
		node.quntity = rand() % 20 + 1;

		push(heap, node, &tail);
	}	


	for (int i = 1;i <= tail;++i) {
		printf("%c: %d\n", heap[i].alphabet, heap[i].quntity);
	}

	return 0;
}

