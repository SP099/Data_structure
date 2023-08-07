#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
    // Allocate memory for new node
    Tree_t *new = malloc(sizeof(Tree_t));
    
    // Check if allocation is successful
    if(new == NULL)
    {
        return FAILURE; // Return FAILURE if memory allocation fails
    }
    new -> data = data; // Set the data of the new node to the given data
    new -> left = NULL; // Set the left child of the new node to NULL
    new -> right = NULL;  // Set the right child of the new node to NULL
    
    // If the tree is empty, set the new node as the root
    if(*root == NULL)
    {
        *root = new;
        return SUCCESS;  // Return SUCCESS after setting the root
    }
    
    // Create temporary pointers to traverse the tree
    Tree_t *temp = *root, *parent = *root;
    
    // Traverse the tree until the correct position to insert the new node is found
    while(temp)
    {
        // If the data is less than the current node's data, move to the left child
        if(data < temp -> data)
        {
            parent = temp;
            temp = temp -> left;
        }
        
        // If the data is greater than the current node's data, move to the right child
        else if(data > temp -> data)
        {
            parent = temp;
            temp = temp -> right;
        }
        
        // If the data already exists in the tree, free the allocated memory for the new node and 
        else
        {
            free(new);
            return DUPLICATE;
        }
    }
    
    // If the data is less than the parent node's data, insert the new node 
    if(parent -> data > data)
    {
        parent -> left = new;
    }
    
    // If the data is greater than the parent node's data, insert the new node as the right child
    else
    {
        parent -> right = new;
    }
    return SUCCESS;
}