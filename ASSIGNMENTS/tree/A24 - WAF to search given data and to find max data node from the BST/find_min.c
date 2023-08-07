#include "tree.h"

int findmin(Tree_t * root)
{
    /* If the root is NULL, the tree is empty */
    if(root == NULL)
    {
         /* Return a failure code */
	   return FAILURE;
    }

    /* If the left subtree of the root exists, recursively search it */
    if(root->left)
    {
        /* Traverse down the left subtree */
    	findmin(root->left);
    }
    else
    {
    	/* If the left subtree does not exist, the current node has the smallest value */
        return(root->data); /* Return the minimum value */
    }
}
