/* QUEUE IMPLEMENTATION USING ARRAY (C VERSIION) */

#ifndef QUEUE_ARRAY_H
#define MAX_SIZE 100

typedef struct Queue {
  int line[MAX_SIZE];
  int head;
  int tail;
  int size;
}queue_arr;

// initialize a queue
void init_queue(queue_arr* queue_ref) {
  queue_ref->head = -1;
  queue_ref->tail = -1;
  queue_ref->size = 0;
}

#ifndef STDBOOL_H
#include <stdbool.h>
#endif

bool is_empty_arr(queue_arr queue) {
  return queue.head == -1 && queue.head == queue.tail;
}

bool is_full_arr(queue_arr queue) {
  return queue.size >= MAX_SIZE || queue.tail == MAX_SIZE - 1;
}

// returns queue size (or count)
int queue_size_arr(queue_arr queue) {
  return queue.size;
}

// 
void print_queue_arr(queue_arr queue) {
  if(is_empty_arr(queue)) return;
  for (int i=queue.head; i<=queue.tail; i++)
    printf("%d ", queue.line[i]);
  printf("\n");
}

// add data to the queue
void enqueue_arr(queue_arr* queue_ref, int data) {
  if(is_full_arr(*queue_ref)) return;
  if(is_empty_arr(*queue_ref)) queue_ref->head++ ;
  queue_ref->line[++queue_ref->tail] = data;
  queue_ref->size++ ;
}

// remove data from the queue
int dequeue_arr(queue_arr* queue_ref) {
  if(is_empty_arr(*queue_ref)) return 0;
  if(queue_size_arr(*queue_ref) == 1) {
    int data = queue_ref->line[queue_ref->head];
    init_queue(queue_ref);
    return data;
  }
  queue_ref->size-- ;
  return queue_ref->line[queue_ref->head++];
}

// returns the head (front) of the queue
int front_arr(queue_arr queue) {
  if(is_empty_arr(queue)) return 0;
  return queue.line[queue.head];
}

// returns the tail (rear) of the queue
int rear_arr(queue_arr queue) {
  if(is_empty_arr(queue)) return 0;
  return queue.line[queue.tail];
}

#endif
