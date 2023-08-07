#include "tree.h"

/* Function to print the tree in pre order */
int preorder(Tree_t *root)
{
    
    //condition to check whether root is NULL or not
    if(root != NULL)
    {
    	//printing parent data
     	printf("%d ", root->data);
     	
      	//recursively calling preorder function to print left side data
	    preorder(root->left);
	    
    	//recursively calling function to print right side data
    	preorder(root->right);
    }
    return FAILURE;
}