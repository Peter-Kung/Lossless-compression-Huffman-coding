#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include <stdio.h>
#include "huffmancode.h"
#endif

/* Given a heap array, return huffman tree root */
TreeNode_t *createHuffmanTree(TreeNode_t **heap, int *last)
{	
	while (*last != 1) {
		TreeNode_t *nodea = pop(heap, last);
		TreeNode_t *nodeb = pop(heap, last);
		
		TreeNode_t *nodec = (TreeNode_t *)malloc(sizeof(TreeNode_t));
		nodec->quntity = nodea->quntity + nodeb->quntity;

		strcpy(nodec->alphabet, nodea->alphabet);
		strcat(nodec->alphabet, nodeb->alphabet);

		nodec->left = nodea;
		nodec->right = nodeb;

		push(heap, nodec, last);
	}


	return heap[1];
}


