#include "minheap.h"

TreeNode_t *createMinHeap(int n)
{
	TreeNode_t *heap = (TreeNode_t *)malloc(sizeof(TreeNode_t) * (n+1));
	memset(heap, 0, sizeof(TreeNode_t) * (n + 1));
	return heap;
}

void push(TreeNode_t *heap, TreeNode_t node, int *tail)  
{
	heap[++(*tail)] = node;

	int cur = *tail;
	while (cur >= 1) {
		
		if (heap[cur / 2].quntity > heap[cur].quntity) {
			swap(&heap[cur / 2], &heap[cur]);
		} else {
			break;
		}

	}
}

TreeNode_t pop(TreeNode_t *heap, int *tail)
{
	TreeNode_t result = heap[1];
	heap[1] = heap[(*tail)--];

	int cur = 1;
	while ((2 * cur <= *tail) && (2 * cur + 1 <= *tail) && 
			(heap[cur].quntity > heap[cur * 2].quntity || heap[cur].quntity > heap[cur * 2 + 1].quntity)
		) {
		
		int nodea =  heap[cur * 2].quntity;
	       	int nodeb =  heap[cur * 2 + 1].quntity; 
		
		if (nodea < nodeb) {
			swap(&heap[cur], &heap[cur * 2]);	
			cur = cur*2;
		} else {
			swap(&heap[cur], &heap[cur * 2 + 1]);	
			cur = cur*2 + 1;
		}
	}
	return  result;
}

void swap(TreeNode_t *node_a, TreeNode_t *node_b) 
{
	char c = node_a->alphabet;
	node_a->alphabet = node_b->alphabet;
	node_b->alphabet = c;

	int q = node_a->quntity;
	node_a->quntity = node_b->quntity;
	node_b->quntity = q;
}
