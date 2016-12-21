#define main_c

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif

#ifndef string_h
#define string_h
#include <string.h>
#endif

#include "./Linked_List/linked_list.c"
#include "./Stack/stack.c"
#include "./Queue/queue.c"

int main(int argc, char const *argv[]) {
  LinkedList list = LINKEDLIST_INIT();

  Node node1 = NODE_INIT(value, 1);
  append(&list, &node1);

  Node node2 = NODE_INIT(value, 2);
  prepend(&list, &node2);

  printList(&list);

  Stack stack = STACK_INIT();

  Node node3 = NODE_INIT(value, 3);
  push(&stack, &node3);

  Node node4 = NODE_INIT(value, 4);
  push(&stack, &node4);

  printStack(&stack);

  Node* poppedNode = pop(&stack);
  printf("Popped Node: %d\n", poppedNode->value);
  printStack(&stack);

  Queue queue = QUEUE_INIT();

  Node node5 = NODE_INIT(value, 5);
  enqueue(&queue, &node5);

  Node node6 = NODE_INIT(value, 6);
  enqueue(&queue, &node6);

  printQueue(&queue);

  Node* dequeuedNode = dequeue(&queue);
  printf("Dequeued Node: %d\n", dequeuedNode->value);
  printQueue(&queue);

  return 0;
}
