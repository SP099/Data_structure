#include "tree.h"

int findmin(Tree_t * root)
{
    //Traverse till temp reaches null
    while(root->left != NULL)
    {
    	//update root with root of left data
     	root=root->left;
    }
    return root->data;
}
