#pragma once

typedef struct node {
  // the data stored in the node
  int data;
  // pointer to the next node in the list
  struct node *next;
    // pointer to the previous node in the list
  struct node *prev;
} node_t;

// create_node returns a pointer to a newly created node with the given data.
// If memory allocation fails, it returns NULL.
// The next or previous pointer of the new node is initialized to NULL.
// Remeber to free the allocated memory when it is no longer needed.
node_t *create_node(int data);

// free_node frees the memory allocated for the linked list starting from head.
void free_node(node_t *head);

// push_node_in_tail adds the given node at the end of the linked list starting from head.
// It returns true if the operation is successful, false otherwise.
bool push_node_in_tail(node_t *head, node_t *node);

// pop_node_from_tail removes the last node from the linked list starting from head.
// It returns true if the operation is successful, false otherwise.
bool pop_node_from_tail(node_t **head);

// push_node_in_head adds the given node at the beginning of the linked list.
// It returns true if the operation is successful, false otherwise.
bool push_node_in_head(node_t **head, node_t *node);
