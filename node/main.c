#include <stdlib.h>

#include "node.h"

int main(void) {
  node_t *head = create_node(10);
  if (head == NULL) {
    return 1;
  }

  // TODO leslie: add your tests here
  return 0;
}
