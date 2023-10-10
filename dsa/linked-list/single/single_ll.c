#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_LIST_ERROR "The list is empty."
#define INVALID_POS_ERROR "Invalid position."

typedef struct Node {
  int data;
  struct Node* next;
}node;

bool is_empty(node* head) {
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
  if(is_empty(head)) {
    printf("%s\n", EMPTY_LIST_ERROR);
    return;
  }
  node* H = head;
  printf("head -> ");
  while(H != NULL) {
    printf("%d -> ", H->data);
    H = H->next;
  }
  printf("NULL\n");
}

void print_reverse_list(node* head) {
  if(head == NULL) return;
  node* H = head;
  int size = list_size(head);
  int arr[size];
  for(int i=0; i<size; i++) {
    arr[i] = H->data;
    H = H->next;
  }
  printf("NULL");
  for(int i=size-1; i>=0; i--)
    printf(" <- %d", arr[i]);
  printf(" <- head\n");
}

void print_list_rec(node* head) {
  if(is_empty(head)) {
    printf("\n");
    return;
  }
  printf("%d ", head->data);
  print_list_rec(head->next);
}

void print_reverse_list_rec(node* head) {
  if(list_size(head) == 0) return;
  print_reverse_list_rec(head->next);
  printf("%d ", head->data);
}

node* create_node(int d) {
  node* N = (node*)malloc(sizeof(node));
  N->data = d;
  N->next = NULL;
  return N;
}

void insert_beg(node** head_ref, node* N) {
  N->next = *head_ref;
  *head_ref = N;
}

void insert_end(node** head_ref, node* N) {
  if(is_empty(*head_ref)) {
    insert_beg(head_ref, N);
    return;
  }
  node* H = *head_ref;
  while(H->next != NULL)
    H = H->next;
  H->next = N;
  N->next = NULL;
}

void insert_at(node** head_ref, node* N, int pos) {
  if(pos == 1) insert_beg(head_ref, N);
  else if(is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  else if(pos > list_size(*head_ref) + 1 || pos < 1) printf("%s\n", INVALID_POS_ERROR);
  else {
    node* H = *head_ref;
    int i = 1;
    while(i < pos - 1){
      H = H->next;
      i++ ;
    }
    N->next = H->next;
    H->next = N;
  }
}

void delete_beg(node** head_ref) {
  if(is_empty(*head_ref)) return;
  node* first_node = *head_ref;
  *head_ref = (*head_ref)->next;
  free(first_node);
}

void delete_end(node** head_ref) {
  if(is_empty(*head_ref)) return;
  if(list_size(*head_ref) == 1) {
    delete_beg(head_ref);
    return;
  }
  node* H = *head_ref;
  while(H->next->next != NULL)
    H = H->next;
  node* last_node = H->next;
  H->next = NULL;
  free(last_node);
}

void delete_at(node** head_ref, int pos) {
  if(is_empty(*head_ref)) printf("%s\n", EMPTY_LIST_ERROR);
  else if(pos > list_size(*head_ref) || pos < 1) printf("%s\n", INVALID_POS_ERROR);
  else if(pos == 1) delete_beg(head_ref);
  else {
    node* tmp = *head_ref;
    int i = 1;
    while(i < pos - 1) {
      tmp = tmp->next;
      i++ ;
    }
    node* node_at_pos = tmp->next;
    tmp->next = node_at_pos->next; // or tmp->next->next
    free(node_at_pos);
  }
}

void reverse_list(node** head_ref) {
  if(is_empty(*head_ref)) return;
  node *prv = NULL, *cur = *head_ref, *nxt;
  while(cur != NULL) {
    nxt = cur->next;
    cur->next = prv;
    prv = cur;
    cur = nxt;
  }
  *head_ref = prv;
}

void reverse_list_rec(node** head_ref) {
  if (*head_ref == NULL || (*head_ref)->next == NULL) return;
  node* rest = (*head_ref)->next;
  reverse_list_rec(&rest);
  (*head_ref)->next->next = *head_ref;
  (*head_ref)->next = NULL;
  *head_ref = rest;
}

int main() {
  node* head = NULL; // Initialize an empty list

  // Test insert_beg
  insert_beg(&head, create_node(1));
  insert_beg(&head, create_node(2));
  insert_beg(&head, create_node(3));
  printf("List after insert_beg: ");
  print_list(head);

  // Test insert_end
  insert_end(&head, create_node(4));
  insert_end(&head, create_node(5));
  printf("List after insert_end: ");
  print_list(head);

  // Test insert_at
  insert_at(&head, create_node(6), 3);
  printf("List after insert_at(6, 3): ");
  print_list(head);

  // Test delete_beg
  delete_beg(&head);
  printf("List after delete_beg: ");
  print_list(head);

  // Test delete_end
  delete_end(&head);
  printf("List after delete_end: ");
  print_list(head);

  // Test delete_at
  delete_at(&head, 2);
  printf("List after delete_at(2): ");
  print_list(head);

  // Test reverse_list_rec
  reverse_list_rec(&head);
  printf("List after reverse_list_rec: ");
  print_list(head);

  return 0;
}
