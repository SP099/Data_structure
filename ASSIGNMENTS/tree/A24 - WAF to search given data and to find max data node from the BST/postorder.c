#include "tree.h"

/* Function to print the tree in post order */
int postorder(Tree_t *root)
{
    //condition to check whether root is null or not
    if(root != NULL)
    {
      	//calling postorder function recursively to print left side data
    	postorder(root->left);
    	
    	//calline postorder function recursivley to print right side data
    	postorder(root->right);
    	
    	//printing data
    	printf("%d ",root->data);
    }
    return FAILURE;
}