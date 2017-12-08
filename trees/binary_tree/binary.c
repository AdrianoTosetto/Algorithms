#include "binary.h"


bool compare(tElement *e1, tElement *e2) {
	return e1->val > e2->val;
}

PtABPNode createNode(tElement e) {
	PtABPNode node;

	if((node = (PtABPNode) malloc(sizeof(struct abpnode))) == NULL) return NULL;

	if((node->e = (tElement * )malloc(sizeof(tElement))) == NULL) {
		free(node);
		return NULL;
	}

	*node->e = e;
	node->left  = NULL;
	node->right = NULL;

	printf("%d\n", (*node->e).val);

	return node;
}

void nodeDestroy(PtABPNode *node) {
	free((*node)->e);
	free(*node);
	node = NULL;
}

uint32_t treeSize(PtABPNode root) {
	if(root == NULL) return 0;
	return 1 + treeSize(root->left) + treeSize(root->right);
}

void insert(PtABPNode *root, tElement e) {

	PtABPNode node = *root, prev = NULL;
	if(*root == NULL) 
		*root = createNode(e);

	while(node != NULL)  {
		prev = node;

		if((*node)->e.val > e.val) 
			node = node->left;
		else if((*node)->e.val < e.val)
			node = node->right;

		else return;
	}

	if((*node).e->val > e.val)
		prev->left = createNode(e);
	else
		prev->right = createNode(e);
}