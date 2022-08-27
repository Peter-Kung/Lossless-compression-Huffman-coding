#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include "huffmancode.h"
#include <time.h>

TreeNode_t *createNode(char c , int count) {

        TreeNode_t *node = (TreeNode_t *)malloc(sizeof(TreeNode_t));
        node->left = node->right = NULL;
        (node->alphabet)[0] = c;
        (node->alphabet)[1] = '\0';
        node->quntity = count;

        return node;

}

void dfs(TreeNode_t *root, char *s, int s_index, FILE *fp, char (*symbal_table)[100]) {


	if (!root->left  && !root->right) {
		s[s_index] = 0;
		fprintf(fp, "%s %s\n", root->alphabet, s);
		strcpy(symbal_table[root->alphabet[0] - 'A'], s);
		return ;
	}
	
	s[s_index] = '0';
	s[s_index + 1] = '\0';
	dfs(root->left, s, s_index + 1, fp, symbal_table);
	s[s_index] = '1';
	s[s_index + 1] = '\0';
	dfs(root->right, s, s_index + 1, fp, symbal_table);


}

#define TEST_DATA "OriginalData.txt"

int main()
{
	
	srand(time(NULL));
	
	TreeNode_t **heap;
	int index = 10;
	heap = createMinHeap(index);
	int tail = 0;

	/* build minheap */
	int count[26] = {0};
	FILE *fp = fopen(TEST_DATA, "r");
	char c;
	puts("Source Data: ");
	while (fscanf(fp, "%c", &c) != EOF) {
		putchar(c);
		count[c - 'A']++;
	}

	for (int i = 0;i < 26;++i)
		if (count[i] != 0) {
                	push(heap, createNode('A' + i, count[i]), &tail);
		}

	TreeNode_t *root = createHuffmanTree(heap, &tail);

	/* build huffman tree */
	char symbal_table[26][100] = {0};	

	char symbal[100] = {0};
	FILE *huffmancode = fopen("HuffmanCode.txt", "w+");
	dfs(root, symbal, 0, huffmancode, symbal_table);

	fclose(huffmancode);

	/* compress data */
	fp = fopen(TEST_DATA, "r");
	FILE *encoding = fopen("encoding.txt", "w+");
	fputs("", encoding);
	while (fscanf(fp, "%c", &c) != EOF) {
		//puts(symbal_table[c - 'A']);
		fprintf(encoding, "%s", symbal_table[c - 'A']);
	}
	fputs("\n", encoding);
	fclose(fp);
	fclose(encoding);


	/* decode data */
	puts("Decode Data: ");
	char current_data[100] = {0};
	int current_index = 0;
	encoding = fopen("encoding.txt", "r");
	FILE *decoding = fopen("decoding.txt", "w+"); 
	while (fscanf(encoding, "%c", &c) != EOF) {
		current_data[current_index++] = c;
		for (int i = 0;i < 26;++i) {
			if (!strcmp(current_data, symbal_table[i])) {
				fputc('A' + i, decoding);
				putchar('A' + i);
				memset(current_data, 0, 100);
				current_index = 0;
				break;
			}
		}
	}
	puts("\n");
	fputs("\n", decoding);
	fclose(encoding);
	fclose(decoding);	

	return 0;
}

