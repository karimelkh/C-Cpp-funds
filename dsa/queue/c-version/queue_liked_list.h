/* QUEUE IMPLEMENTATION USING ARRAY (C VERSIION) */

#ifndef QUEUE_LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node* next;
}node;

typedef struct Queue_ll {
  node* head;
  node* tail;
  int size;
}queue_ll;

#ifndef STDLIB_H
#include <stdlib.h>
#endif

// initialize a queue
void init_queue_ll(queue_ll* queue_ref) {
  queue_ref->head = NULL;
  queue_ref->tail = NULL;
  queue_ref->size = 0;
}

#ifndef STDBOOL_H
#include <stdbool.h>
#endif

bool is_empty_ll(queue_ll queue) {
  return queue.head == NULL && queue.tail == NULL;
}

// returns queue size (or count)
int queue_size_ll(queue_ll queue) {
  return queue.size;
}

node* create_node(int data) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void print_queue_ll(queue_ll queue) {
  if(is_empty_ll(queue)) return;
  while(queue.head != NULL) {
    printf("%d ", queue.head->data);
    queue.head = queue.head->next;
  }
  printf("\n");
}

// add data to the queue
void enqueue_ll(queue_ll* queue_ref, int data) {
  node* new_node = create_node(data);
  if(is_empty_ll(*queue_ref)) queue_ref->head = new_node;
  if(queue_ref->tail != NULL) queue_ref->tail->next = new_node;
  queue_ref->tail = new_node;
  queue_ref->size++ ;
}

// remove data from the queue
int dequeue_ll(queue_ll* queue_ref) {
  if(is_empty_ll(*queue_ref)) return 404;
  node* to_delete = queue_ref->head;
  int data = to_delete->data;
  queue_ref->head = queue_ref->head->next;
  free(to_delete);
  queue_ref->size-- ;
  return data;
}

// returns the head (front) of the queue
int front_ll(queue_ll queue) {
  if(!is_empty_ll(queue)) return queue.head->data;
  return 404;
}

// returns the tail (rear) of the queue
int rear_ll(queue_ll queue) {
  if(!is_empty_ll(queue)) return queue.tail->data;
  return 404;
}

#endif
