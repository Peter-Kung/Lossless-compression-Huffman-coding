#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include <time.h>

TreeNode_t *createNode() {
	
	TreeNode_t *node = (TreeNode_t *)malloc(sizeof(TreeNode_t));
	node->left = node->right = NULL;
	strcpy(node->alphabet, "A");
	node->quntity = rand() % 20 + 1;

	return node;

}

int main()
{
	
	srand(time(NULL));
	
	TreeNode_t **heap;
	int index = rand() % 100 + 1;
	heap = createMinHeap(index);
	int tail = 0;

	for (int i = 0;i < 10;++i)
		push(heap, createNode(), &tail);

	puts("\n----------------\n");

	for (int i = 1;i <= tail;++i) {
		printf("[%d]: %d\n", i, heap[i]->quntity);
	}

	puts("\n----------------\n");

	for (int i = 0;i < 5;++i) {
		TreeNode_t *tmp = pop(heap, &tail);
		printf("[%d]: %d\n", i, tmp->quntity);
	}
	puts("\n----------------\n");

	for (int i = 1;i <= tail;++i) {
		printf("[%d]: %d\n", i, heap[i]->quntity);
	}


	return 0;
}

