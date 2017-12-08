#include "binary.h"


int main(int argc, char const *argv[])
{

	tElement e1;
	e1.val = 10;

	PtABPNode root = createNode(e1);

	tElement e2;
	e2.val = 14;

	insert(root, e2);
	
	return 0;
}