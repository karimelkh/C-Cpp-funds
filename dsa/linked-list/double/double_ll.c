#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_LIST_ERROR "The list is empty."
#define INVALID_POS_ERROR "Invalid position."

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
}node;

bool list_is_empty(node* head) {
  if(head == NULL) return true;
  return false;
}

int list_size(node* head) {
  int size = 0;
  while(head != NULL) {
    head = head->next;
    size++ ;
  }
  return size;
}

void print_list(node* head) {
  if(list_is_empty(head)) printf("%s\n", EMPTY_LIST_ERROR);
  else {
    printf("head -> ");
    while (head->next != NULL) {
      printf("%d <=> ", head->data);
      head = head->next;
    }
    printf("%d -> NULL\n", head->data);
  }
}

void print_reverse_list(node* head) {
  if(list_is_empty(head)) printf("%s\n", EMPTY_LIST_ERROR);
  else {
    while(head->next != NULL)
      head = head->next;
    printf("NULL <- ");
    while(head->prev != NULL) {
      printf("%d <=> ", head->data);
      head = head->prev;
    }
    printf("%d <- head\n", head->data);
  }
}

node* create_node(int d) {
  node* N = (node*) malloc(sizeof(node));
  N->data = d;
  N->next = N->prev = NULL;
  return N;
}

void insert_beg(node** head_ref, node* N) {
  if(*head_ref != NULL) (*head_ref)->prev = N;
  N->next = *head_ref;
  *head_ref = N;
}

void insert_end(node** head_ref, node* N) {
  if(list_is_empty(*head_ref)) insert_beg(head_ref, N);
  else {
    node* tmp = *head_ref;
    while(tmp->next != NULL)
      tmp = tmp->next;
    N->prev = tmp;
    tmp->next = N;
  }
}

void insert_at(node** head_ref, node* N, int pos) {
  if(pos == 1) insert_beg(head_ref, N);
  else if(list_is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  else if(pos > list_size(*head_ref) + 1 || pos < 1) printf("%s\n", INVALID_POS_ERROR);
  else {
    node* tmp = *head_ref;
    int i = 1;
    while(i < pos - 1) {
      tmp = tmp->next;
      i++ ;
    }
    N->prev = tmp;
    N->next = tmp->next;
    tmp->next = N;
  }
}

void delete_beg(node** head_ref) {
  if(list_is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  else {
    node* first_node = *head_ref;
    if(list_size(*head_ref) > 1) first_node->next->prev = NULL;
    *head_ref = (*head_ref)->next;
    free(first_node);
  }
}

void delete_end(node** head_ref) {
  if(list_is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  else {
    node* last_node = *head_ref;
    while(last_node->next != NULL)
      last_node = last_node->next;
    if(last_node->prev != NULL) last_node->prev->next = NULL;
    else *head_ref = NULL;
    free(last_node);
  }
}

void delete_at(node** head_ref, int pos) {
  if(list_is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  int size = list_size(*head_ref);
  if(pos > size || pos < 1) printf("%s\n", INVALID_POS_ERROR);
  if(pos == 1) delete_beg(head_ref);
  else {
    node* node_at_pos = *head_ref;
    int i = 1;
    while(i < pos) {
      node_at_pos = node_at_pos->next;
      i++ ;
    }
    node_at_pos->prev->next = node_at_pos->next;
    node_at_pos->next->prev = node_at_pos->prev;
    free(node_at_pos);
  }
}

void reverse_list(node** head_ref) {
  node* current_node = *head_ref;
  node* next_node;
  while(current_node != NULL) {
    next_node = current_node->next;
    if(next_node == NULL) *head_ref = current_node;
    current_node->next = current_node->prev;
    current_node->prev = next_node;
    current_node = next_node;
  }
}

int main() {
  node* head = NULL;
  for(int i=1; i<6; i++)
    insert_at(&head, create_node(i), i);

  print_list(head);
  print_reverse_list(head);

  insert_beg(&head, create_node(0));
  insert_end(&head, create_node(6));
  print_list(head);

  delete_at(&head, 3);
  print_list(head);

  delete_end(&head);
  delete_beg(&head);
  print_list(head);

  reverse_list(&head);
  print_list(head);
  return 0;
}
