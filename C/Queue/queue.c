#ifndef Queue_c
#define Queue_c

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif

#include "../Linked_List/linked_list.c"

// Define Linked List
typedef struct Queue_s {
  int length;
  struct LinkedList_s list;
} Queue;
#define QUEUE_INIT() { .length = 0, .list = LINKEDLIST_INIT() }

// Methods
void enqueue(Queue* queue, Node* newNode) {
  if (queue == NULL) {
    printf("ERROR: Queue* queue is NULL.\n");
    fflush(stdout);
    return;
  }
  if (newNode == NULL) {
    printf("ERROR: Node to enqueue is NULL.\n");
    fflush(stdout);
    return;
  }
  append(&queue->list, newNode);
  queue->length++;
  return;
}

Node* dequeue(Queue* queue) {
  if (queue == NULL) {
    printf("ERROR: Queue* queue is NULL.\n");
    fflush(stdout);
    return NULL;
  }
  if (queue->length == 0) {
    printf("ERROR: Cannot delete from an dequeue queue.\n");
    fflush(stdout);
    return NULL;
  }
  Node* node = getNode(&queue->list, 0);
  delete(&queue->list, 0);
  return node;
}

void printQueue(Queue* queue) {
  printList(&queue->list);
}

#endif
