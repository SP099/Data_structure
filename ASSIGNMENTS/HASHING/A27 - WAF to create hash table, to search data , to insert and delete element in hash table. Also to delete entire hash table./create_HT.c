#include "hash.h"

void create_HT(hash_t *HT, int size)
{
    // Initialize the index and value fields of each node to 0
    for (int i = 0; i < size; i++)
    {
        HT[i].index = i;
        HT[i].value = -1;
        HT[i].link = NULL;
    }
}