#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

struct _node {
	int data;
	struct _node *next_prev;
};

typedef struct _node node;

node* xor(node* a, node *b) {
	return (node*)  ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void init_node(int data, node* n, node *prev, node *next) {
	//n = malloc(sizeof(struct _node));
	//n->next_prev = malloc(sizeof(struct _node));

	n->data = data;
	n->next_prev = xor(prev, next);
	//return new;
} 

node* next(node* n, node* prev) {

	node* ret;

	return (ret =  xor(prev, n->next_prev));
}

node* prev(node *n, node* next) {
	return xor(n->next_prev, next);
}

void insert(node *head, int data) {
	//node *new = (node*) malloc(sizeof(struct _node));

	//for (node *n = head; n != NULL; )
}

int main(int argc, char const *argv[])
{
	node *head = malloc(sizeof(node));
	node *n1   = malloc(sizeof(node));
	node *n2   = malloc(sizeof(node));
	node *n3   = malloc(sizeof(node));
	node *n4   = malloc(sizeof(node));

	init_node(0, head, NULL, n1);
	init_node(1, n1, head, n2);
	init_node(2, n2, n1,n3);
	init_node(3, n3, n2, n4);
	init_node(4, n4, n3, NULL);

	bool stop = false;

	node *curr = head;
	node *before = NULL;

	while(!stop) {

		printf("%d\n", curr->data);
		node *saved = before;
		before = curr;
		curr = next(curr, saved);

		sleep(1);
	}


	return 0;
}