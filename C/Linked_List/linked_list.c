#ifndef linked_list_c
#define linked_list_c

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif

// Define Node
typedef struct Node_s {
  int value;
  struct Node_s* next;
} Node;
#define NODE_INIT(param, value) \
{ .param = value, .next = NULL }

// Define Linked List
typedef struct LinkedList_s {
  int length;
  struct Node_s* head;
} LinkedList;
#define LINKEDLIST_INIT() { .length = 0, .head = NULL }

// Methods
Node* getNode(LinkedList* list, int index) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    fflush(stdout);
    return NULL;
  }
  if (index < 0) {
    printf("ERROR: Index value cannot be negative.\n");
    fflush(stdout);
    return NULL;
  }
  if (index >= list->length) {
    printf("ERROR: Index value is out of range.\n");
    fflush(stdout);
    return NULL;
  }
  Node* currentNode = list->head;
  for (int i = 0; i < index; i++) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

void append(LinkedList* list, Node* newNode) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    fflush(stdout);
    return;
  }
  if (newNode == NULL) {
    printf("ERROR: Node* newNode is NULL.\n");
    fflush(stdout);
    return;
  }
  if (list->length == 0) {
    list->head = newNode;
    list->length++;
    return;
  }
  Node* currentNode = list->head;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
  list->length++;
  return;
}

void prepend(LinkedList* list, Node* newNode) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    fflush(stdout);
    return;
  }
  if (newNode == NULL) {
    printf("ERROR: Node* node is NULL.\n");
    fflush(stdout);
    return;
  }
  if (list->length == 0) {
    list->head = newNode;
    list->length++;
    return;
  }
  Node* currentNode = list->head;
  list->head = newNode;
  newNode->next = currentNode;
  list->length++;
  return;
}

void insert(LinkedList* list, Node* newNode, int index) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    fflush(stdout);
    return;
  }
  if (newNode == NULL) {
    printf("ERROR: Node* newNode is NULL.\n");
    fflush(stdout);
    return;
  }
  if (index < 0) {
    printf("ERROR: Index cannot be negative.\n");
    fflush(stdout);
    return;
  }
  if (index > list->length) {
    printf("ERROR: Index is out of bounds.\n");
    fflush(stdout);
    return;
  }
  if (index == 0) {
    prepend(list, newNode);
  }
  if (index == list->length) {
    append(list, newNode);
  }
  Node* previousNode = getNode(list, index - 1);
  Node* currentNode = getNode(list, index);
  previousNode->next = newNode;
  newNode->next = currentNode;
  list->length++;
  return;
}

void delete(LinkedList* list, int index) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    fflush(stdout);
    return;
  }
  if (list->length == 0) {
    printf("ERROR: Cannot delete from an empty list.\n");
    fflush(stdout);
    return;
  }
  if (index < 0) {
    printf("ERROR: Index cannot be negative.\n");
    fflush(stdout);
    return;
  }
  if (index >= list->length) {
    printf("ERROR: Index is out of bounds.\n");
    fflush(stdout);
    return;
  }
  if (index == 0) {
    Node* currentNode = getNode(list, index);
    list->head = currentNode->next;
    currentNode->next = NULL;
    list->length--;
    return;
  }
  Node* previousNode = getNode(list, index - 1);
  Node* currentNode = getNode(list, index);
  previousNode->next = currentNode->next;
  currentNode->next = NULL;
  list->length--;
  return;
}

void printList(LinkedList* list) {
  if (list == NULL) {
    printf("ERROR: LinkedList* list is NULL.\n");
    return;
  }
  printf("List:     %d\nElements: %d\n[\n", list, list->length);
  for (int i = 0; i < list->length; i++) {
    if (i == (list->length - 1)) {
      printf("  %d\n", getNode(list, i)->value);
    } else {
      printf("  %d,\n", getNode(list, i)->value);
    }
  }
  printf("]\n");
}

// #ifndef main_c
//
// int main(int argc, char const *argv[]) {
//   LinkedList list = LINKEDLIST_INIT();
//
//   Node node1 = NODE_INIT(value, 1);
//   // node1.value = 1;
//   append(&list, &node1);
//
//   Node node2 = NODE_INIT(value, 2);
//   // node2.value = 2;
//   prepend(&list, &node2);
//
//   printList(&list);
//   return 0;
// }
//
// #endif

#endif
