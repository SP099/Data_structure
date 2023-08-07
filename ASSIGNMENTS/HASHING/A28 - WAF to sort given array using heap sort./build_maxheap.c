#include "main.h"

void build_maxheap(int *heap, int size)
{
    // Calculate the index of the last non-leaf node in the heap
    int last_non_leaf = size / 2 - 1;

    // Iterate from the last non-leaf node to the root of the heap
    for (int i = last_non_leaf; i >= 0; i--) 
    {
        // Call the max_heap() function on the current node
        max_heap(heap, i, size);
    }
}