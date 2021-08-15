#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <../include/binary_tree.h>

// Create new empty node
node_t *allocnode()
{
    node_t *n = (node_t *) malloc(sizeof(node_t));
    n->left = NULL;
    n->right = NULL;
    n->data = NULL;
    n->key = NULL;
    return n;
}

// Insert new node into tree
node_t *insert(node_t *root, char *key, void *data)
{
    if (root == NULL)
    {
        node_t *new_node = allocnode();
        new_node->data = data;
        new_node->key = key;
        return new_node;
    }
    
    // Compare key and call function recursively with left or right child
    if (strcmp(key, root->key) < 0)
    {
        root->left = insert(root->left, key, data);
        return root;
    }
    else if (strcmp(key, root->key) > 0)
    {
        root->right = insert(root->right, key, data);
        return root;
    }

    // If key exists in tree, update node
    root->data = data;

    return root;

}

void print_node(node_t *node)
{
    if (node == NULL)
    {
        return ;
    }
    printf("%s %s\n", node->key, (char *)node->data);
}

// Print the node and all its children
void print_tree(node_t *tree)
{
    if (tree == NULL)
    {
        return ;
    }

    // Print all left children firstly
    if (tree->left != NULL)
    {
        print_tree(tree->left);
    }

    // Print root
    if (tree->left == NULL && tree->right == NULL)
    {
        printf("%s %s\n", tree->key, (char *)tree->data);
        return ;
    }
    
    // Print all right children
    print_tree(tree->right);
}

void destroy_tree(node_t *node, void (fdestroy)(node_t *root))
{
    if (node->left)
    {
        destroy_tree(node->left, fdestroy);
        //free(node->left);
    }
    if (node->right)
    {
        destroy_tree(node->right, fdestroy);
        //free(node->right);
    }

    fdestroy(node);
    free(node);
}

// Visit all nodes and apply given function
void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node == NULL)
    {
        return ;
    }
    
    // Visit all left children
    if (node->left != NULL)
    {   
        visit_tree(node->left, fp);
    }
    
    // Apply function
    if (node->left == NULL && node->right == NULL)
    {   
        fp(node);
        return ;
    }
    
    // Visit all right children
    visit_tree(node->right, fp);
}
