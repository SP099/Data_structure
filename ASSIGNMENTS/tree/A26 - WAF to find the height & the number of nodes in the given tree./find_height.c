/*
Name         : Sushant Patil
Date         : 23/04/2023
description  : WAF to find the height of the given tree.
*/


#include "tree.h"

int find_height(Tree_t *root)
{
    /* If the root node is NULL */
    if (root == NULL) 
    {
        return 0;
    }
    
    /* Recursively find the heights of the left and right subtrees */
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);
    
    /* Return the maximum height of the two subtrees plus one */
    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}
