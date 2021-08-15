#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <../include/linked_list.h>

// Create list
node_t *list_create(void *data)
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    head->next = NULL;
    head->data = data;

    return head;
}

// Destroy list and free memory
void list_destroy(node_t **head, void(*fp)(void *data))
{
    node_t *next;
    node_t *tmp = *head;
    *head = NULL;
    
    // Iterate over list and free all nodes
    while (tmp != NULL)
    {
        fp(tmp->data);
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

// Add node to end of the list
void list_push(node_t *head, void *data)
{  
    node_t *tmp = head;
    // Iterate over list to move pointer to the end
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = list_create(data);
}

// Add node to start of the list
void list_unshift(node_t **head, void *data)
{
    // Create new node and mark head of list as next element
    node_t *new_node = list_create(data);
    new_node->next = *head;
    *head = new_node;
}

// Delete first node
void *list_shift(node_t **head)
{
    node_t *next_node = (*head)->next;
    void *data = (*head)->data;

    //free((*head)->data);
    free(*head);

    *head = next_node;

    return data;
}

// Delete last node
void *list_pop(node_t **head)
{
    void *data;
    if ((*head)->next == NULL)
    {  
        data = (*head)->data;
        free(*head);
        return data;
    }

    node_t *tmp = *head;

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    
    data = tmp->next->data;

    //free(tmp->next->data);
    free(tmp->next);

    tmp->next = NULL;

    return data;
}

// Delete element on n position after head
void *list_remove(node_t **head, int pos)
{
    void *data;
    if ((*head)->next == NULL)
    {
        data = (*head)->data;
        free(*head);
        return data;
    }
    
    int count = 0;
    node_t *tmp = *head;

    while (count != pos - 1)
    {
        tmp = tmp->next;
        count++;
    }

    node_t *next_node = tmp->next->next;
    data = tmp->next->data;

    //free(tmp->data);
    free(tmp->next);

    tmp->next = next_node;

    return data;
}

// Iterate over list and print data of each node on separate line
void list_print(node_t *head)
{
    while (head != NULL)
    {
        printf("%s\n", (char *)(head->data));
        head = head->next;
    }
}

// Apply given function to every list node
void list_visitor(node_t *head, void(*fp)(void *data))
{
    node_t *tmp = head;

    while (tmp != NULL)
    {   
        fp(tmp);
        tmp = tmp->next;
    }

}
