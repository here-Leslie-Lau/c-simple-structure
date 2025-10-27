#include <stdbool.h>
#include <stdlib.h>

#include "node.h"

node_t *create_node(int data) {
  node_t *new = (node_t *)malloc(sizeof(node_t));
  if (new == NULL) {
    return NULL;
  }

  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void free_node(node_t *head) {
  if (head == NULL) {
    return;
  }

  while (head->next != NULL) {
    node_t *temp = head;
    head = head->next;
    free(temp);
  }

  free(head);
}

// find_tail returns the tail node of the linked list starting from any node.
static node_t *find_tail(node_t *node) {
  if (node == NULL) {
    return NULL;
  }

  node_t *curr = node;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  return curr;
}

bool push_node_in_tail(node_t *head, node_t *node) {
  if (head == NULL || node == NULL) {
    return false;
  }

  node_t *curr = find_tail(head);
  if (curr == NULL) {
    return false;
  }

  curr->next = node;
  node->prev = curr;

  return true;
}

bool pop_node_from_tail(node_t **head) {
  if (head == NULL || *head == NULL) {
    return false;
  }

  if ((*head)->next == NULL) {
    // only one node in the list
    free(*head);
    *head = NULL;
    return true;
  }

  node_t *tail = find_tail(*head);

  if (tail->prev != NULL) {
    tail->prev->next = NULL;
  }

  free(tail);
  tail = NULL;

  return true;
}

bool push_node_in_head(node_t **head, node_t *node) {
  if (head == NULL || node == NULL) {
    return false;
  }
  if (*head == NULL) {
    *head = node;
    return true;
  }

  (*head)->prev = node;
  node->next = *head;
  *head = node;

  return true;
}

bool pop_node_from_head(node_t **head) {
  if (head == NULL || *head == NULL) {
    return false;
  }
  node_t *temp = *head;

  *head = (*head)->next;
  if ((*head)->next != NULL) {
    (*head)->prev = NULL;
  }

  free(temp);

  return true;
}
