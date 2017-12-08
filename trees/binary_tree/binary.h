#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct tElement tElement;
typedef struct abpnode* PtABPNode;

struct tElement {
	//void *content;
	int32_t val;
};

struct abpnode {
	PtABPNode left;
	PtABPNode right;
	tElement *e;
};