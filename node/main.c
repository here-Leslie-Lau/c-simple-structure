#include <stdio.h>
#include <stdlib.h>

#include "node.h"

void print_node(node_t *head);

int main(void) {
  node_t *head = create_node(0);
  if (head == NULL) {
    return 1;
  }

  for (int i = 1; i < 10; i++) {
    node_t *node = create_node(i);
    if (push_node_in_tail(head, node) == false) {
      free(node);
      continue;
    }
  }

  print_node(head);

  for (int i = 0; i < 3; i++) {
    if (!pop_node_from_head(&head)) {
      printf("Failed to pop from head\n");
      break;
    }
  }

  print_node(head);

  free_node(head);
  return 0;
}

void print_node(node_t *head) {
  node_t *curr = head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }

  printf("\n");
}
