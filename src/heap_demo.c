#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

int main()
{	
	int MAXELEMENTS=50;
	struct Heap * heap = heap_init(MAXELEMENTS);
	
	int i;
	srand(time(NULL));
	for (i=0;i < MAXELEMENTS; i++) {
		int value = rand()%1000;
		heap_insert(heap, 100-i, (void *)value);

		printf("inserting: %d->%d\n", 100-i, value);
	}
	int key = 51;
	printf("modify a key :%d to %d\n", key, -1);
	heap_modify_key(heap, key, -1);
	while(!heap_is_empty(heap)) {
		printf("deleting min: %d->%d\n", HEAP_MIN_KEY(heap), (int)HEAP_MIN_VALUE(heap));
		heap_delete_min(heap);
	}

	return 0;
}
