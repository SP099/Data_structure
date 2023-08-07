/*
Name            : Sushant Patil
Date            : 23/04/2023
Description     : WAF to delete the given data node from the BST
 */
#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t * delete_BST(Tree_t * root, int data)
{
    // check whether root is empty or not
    if(root==NULL)
    {
        // if root is empty, return failure
        return FAILURE;
    }

    // check data with root data
    if(data < root->data)
    {
        // if data is less than root data, check the left side data's by recursively calling delete function
        root->left = delete_BST(root->left, data);
    }
    else if(data > root->data)
    {
        // if data is greater than root data, check the right side data by calling delete function recursively
        root->right = delete_BST(root->right, data);
    }
    else
    {
        // if root has no left or right child
        if(root->left == NULL && root->right == NULL)
        {
            // free the root node
            free(root);
            // update root with null
            root = NULL;
            // set status to 1 to indicate successful deletion
            status = 1;
        }
        // if root has no left child
        else if(root->left == NULL)
        {
            // declare temp ptr with root
            Tree_t *temp = root;
            // update root with root of right
            root = root->right;
            // set status to 1 to indicate successful deletion
            status = 1;
            // free temp node
            free(temp);
        }
        // if root has no right child
        else if(root->right == NULL)
        {
            // declare temp ptr with root
            Tree_t *temp = root;
            // update root with root of left
            root = root->left;
            // set status to 1 to indicate successful deletion
            status = 1;
            // free temp node
            free(temp);
        }
        // if root has both left and right child
        else
        {
            // declare temp with minimum value of right subtree
            int temp = findmin(root->right);
            // set root data to temp value
            root->data = temp;
            // set status to 1 to indicate successful deletion
            status = 1;
            // delete the node with temp value in right subtree
            root->right = delete_BST(root->right, temp);
        }
    }
    // return the updated root node
    return root;
}