/*
Name         : Sushant Patil
Date         : 23/04/2023
Description  : WAF to sort given array using heap sort.
*/

#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heap(int *heap, int i, int size)
{
    // Calculate the indices of the left and right child nodes
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Initialize the largest value to the current node
    int largest = i;

    // Check if the left child node is larger than the current node
    if (left < size && heap[left] > heap[i]) 
    {
        largest = left;
    } 
    // If the left child node is not larger, the largest remains the current node

    // Check if the right child node is larger than the largest node so far
    if (right < size && heap[right] > heap[largest]) 
    {
        largest = right;
    }

    // If the largest node is not the current node, swap their values
    if (largest != i) 
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        
        // Recursively call max_heap() on the swapped node to continue the max heap process
        max_heap(heap, largest, size);
    }
}

