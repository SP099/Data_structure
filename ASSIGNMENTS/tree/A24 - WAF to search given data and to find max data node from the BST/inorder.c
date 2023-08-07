#include "tree.h"

/* Function to print the data in in order printing */
int inorder(Tree_t *root)
{
    //condition to check root is null or not
    if(root != NULL)
    {
    	//recursively calling the inorder function to print left side data
    	inorder(root->left);
    	
    	//printing data 
    	printf("%d ",root->data);
    	
    	//recursively calling the inorder function to print right side data
    	inorder(root->right);
    }
    return FAILURE;

}