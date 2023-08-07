#include "tree.h"

int findmax(Tree_t * root)
{
    // Check if the root is NULL, and if so, return a failure value
    if(root==NULL)
    {
        return FAILURE;
    }

    // If the right child of the root is non-null, recursively call the function with the right child as input
    if(root->right)
    {
        return findmax(root->right);
        
    }
    // If the right child is NULL, return the value stored in the data field of the current node,
    // which represents the maximum value in the right subtree of the original input node
    else
    {
        return(root->data);
    }
}
