#include "main.h"

/* Function to sort the array using heap sort */
int heap_sort(int *heap, int size )
{
    // Build a max heap from the array
    build_maxheap(heap, size);

    // Iterate over the array in reverse order
    for (int i = size - 1; i >= 1; i--) 
    {
        // Swap the maximum element with the last element in the heap
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // Restore the max heap property on the new root node
        max_heap(heap, 0, i);
    }
    // Return 0 to indicate successful completion of the sorting process
    return 0;
}       
