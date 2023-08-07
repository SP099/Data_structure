#include "sll.h"

int find_node(Slist *head, data_t data)
{
    int count = 0;

    // Check if list is empty
    if (head == NULL) {
        // Case 1: List is empty
        return -1;
    }

    // Traverse the list until the data is found
    Slist *curr = head;
    while (curr != NULL) {
        count++;

        if (curr->data == data) {
            // Case 2: Data found
            return count;
        }

        curr = curr->link;
    }

    // Case 3: Data not found
    return -1; 
}
