#include <stdio.h>
#include <inttypes.h>

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

typedef uint32_t u32;

void quicksort(int seq[], uint32_t begin, uint32_t end) {
	
	#define SWAP(A, B) swap(&seq[A], &seq[B])
	u32 middle, nElem = end - begin + 1, i, j;

	if(nElem <= 1) return;
	if(nElem == 2) {
		if(seq[begin] > seq[end]) SWAP(begin, end);
	}

	middle = ((uint32_t) begin + (uint32_t) end) >> 1;


	#define comparePosition(A, B) if(seq[A] > seq[B]) swap(&seq[A], &seq[B])

	comparePosition(begin, middle);
	comparePosition(begin, end);
	comparePosition(middle, end);
	if(nElem == 3) return;
	
	swap(&seq[middle], &seq[end - 1]);

	i = begin; middle = j = end - 1;
	
	for(;;) {
		while(seq[++i] < seq[middle]);
		while(seq[--j] > seq[middle]);
		
		if(i < j) SWAP(i,j);
		else break;
	}
	middle = i;
	SWAP(middle,end - 1);
	quicksort(seq, begin, middle - 1);
	quicksort(seq, middle + 1, end);
}

int main(int argc, char const *argv[])
{
	int unordered[] = {1, 5, 2, 8, 7};
	quicksort(unordered, 0, 4);
	
	u32 i;
	for(i = 0; i < 5; i++)
		printf("%d\n", unordered[i]);
	return 0;
}
