#ifndef MINHEAP_H
#define MINHEAP_H
#include "minheap.h"
#endif

TreeNode_t **createMinHeap(int n)
{
	TreeNode_t **heap = (TreeNode_t **)malloc(sizeof(TreeNode_t *) * (n+1));
	return heap;
}

/* put new node on last pos, and compare with it's parent */
void push(TreeNode_t **heap, TreeNode_t *node, int *tail)  
{
	heap[++(*tail)] = node;

	int cur = *tail;
	while (cur > 1) {
		
		if (heap[cur / 2]->quntity > heap[cur]->quntity) {
			TreeNode_t *tmp = heap[cur / 2];
			heap[cur / 2] = heap[cur];
			heap[cur] = tmp;
			cur = cur / 2;
		} else {
			break;
		}

	}
}

/* take out first node, replace first node by last node and compare it's child */
TreeNode_t *pop(TreeNode_t **heap, int *tail)
{
	TreeNode_t *result = heap[1];
	heap[1] = heap[(*tail)--];

	int cur = 1;
	while (((2 * cur <= *tail) &&  (heap[cur]->quntity > heap[cur * 2]->quntity)) || 
			((2 * cur + 1 <= *tail) && (heap[cur]->quntity > heap[cur * 2 + 1]->quntity))
		) {
		
		if ((2 * cur <= *tail) && (2 * cur + 1 <= *tail)) {
			int nodea =  heap[cur * 2]->quntity;
	       		int nodeb =  heap[cur * 2 + 1]->quntity; 

			if (nodea < nodeb) {
			
				TreeNode_t *tmp  = heap[cur * 2];
				heap[cur * 2] = heap[cur];
				heap[cur] = tmp;
				cur = cur*2;

			} else {
				TreeNode_t *tmp  = heap[cur * 2 + 1];
				heap[cur * 2 + 1] = heap[cur];
				heap[cur] = tmp;
				cur = cur*2 + 1;
			}
		} else if ( 2 * cur <= *tail) {
			TreeNode_t *tmp  = heap[cur * 2];
			heap[cur * 2] = heap[cur];
			heap[cur] = tmp;
			cur = cur*2;
		}
	}
	return  result;
}
