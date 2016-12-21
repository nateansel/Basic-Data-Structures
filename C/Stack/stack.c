#ifndef Stack_c
#define Stack_c

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif

#include "../Linked_List/linked_list.c"

// Define Stack
typedef struct Stack_s {
  int length;
  struct LinkedList_s list;
} Stack;
#define STACK_INIT() { .length = 0, .list = LINKEDLIST_INIT() }

// Methods
void push(Stack* stack, Node* newNode) {
  if (stack == NULL) {
    return;
  }
  if (newNode == NULL) {
    return;
  }
  prepend(&stack->list, newNode);
  stack->length++;
  return;
}

Node* pop(Stack* stack) {
  Node* first = getNode(&stack->list, 0);
  delete(&stack->list, 0);
  stack->length--;
  return first;
}

void printStack(Stack* stack) {
  printList(&stack->list);
}

// #ifndef main_c
//
// int main(int argc, char const *argv[]) {
//   Stack stack = STACK_INIT();
//
//   Node node3 = NODE_INIT(value, 1);
//   push(&stack, &node3);
//
//   Node node4 = NODE_INIT(value, 2);
//   push(&stack, &node4);
//
//   printf("Finished pushing\n");
//   printStack(&stack);
//
//   Node* poppedNode = pop(&stack);
//   printf("Finished popping\n");
//   printStack(&stack);
//
//   printf("Popped Node: %d\n", poppedNode->value);
//   return 0;
// }
//
// #endif

#endif
