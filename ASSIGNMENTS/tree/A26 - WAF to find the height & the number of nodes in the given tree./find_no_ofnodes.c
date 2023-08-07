/*
Name         : Sushant Patil
Date         : 23/04/2023
description  : WAF to find the number of nodes in the given tree.
*/

#include "tree.h"

int total_nodes(Tree_t *root)
{
    /* Initialize count to 0 using a static variable */
    //static int count = 0;
    
    /* If the root node is NULL*/
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        /* Recursively traverse the left and right subtrees and return the result*/
        return ( total_nodes(root -> left) + 1 + total_nodes(root -> right) );
    }
    
}

