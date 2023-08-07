#include "tree.h"

/* Iteratively */
int search_BST(Tree_t * root, int data)
{
    // If the root is NULL, return FAILURE
    if(root==NULL)
    {
    	return FAILURE;
    }
    
    Tree_t *temp=root;
   
    while(temp != NULL)
    {   
        // Traverse left subtree if data is smaller than temp->data
    	if(temp->data > data)
    	{
	        temp=temp->left;
    	}

        // Traverse right subtree if data is greater than temp->data
    	else if(temp->data < data)
	    {
	        temp=temp->right;
	    }
     	else
    	{
    	    // If data is found in the tree, return SUCCESS
	        return SUCCESS;
	    }
    }
   
    // If data is not found in the tree, return NOELEMENT
    return NOELEMENT;

}