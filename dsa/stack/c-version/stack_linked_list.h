/* STACK LINKED LIST IMPLEMENTATION (C VERSION) */

#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#ifndef STACK_ARR_H
#define UNDERFLOW "stack underflow"
#define EMPTY_STACK "stack is empty"
#endif

typedef struct Node {
  int data;
  struct Node* next;
}node;

typedef struct Stack {
  node* top;
  int stack_count;
}stack_ll;

#ifndef STACK_ARR_H
// log the passed message and break the line
void log_message(const char* message) {
  printf("%s\n", message);
}
#endif

bool is_empty_ll(stack_ll stack) {
  return stack.top == NULL;
}

node* create_node(int d) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->data = d;
  new_node->next = NULL;
  return new_node;
}

// print the element of the stack starting from the top
void print_stack_ll(stack_ll stack) {
  if(is_empty_ll(stack)) log_message(EMPTY_STACK);
  else {
    node* current_node = stack.top; // the print process will start from the top
    while(current_node != NULL) { // loop until the end of the stack
      printf("%d ", current_node->data);
      current_node = current_node->next; // move to the next node
    }
    printf("\n");
  }
}

int get_stack_count_ll(stack_ll stack) {
  return stack.stack_count;
}

// push (add) an element to the stack
void push_ll(stack_ll *stack_ref, node* new_node) {
  new_node->next = stack_ref->top; // new_node points to the old top
  stack_ref->top = new_node; // new_node is the new top now
  stack_ref->stack_count++ ;
}

/*
  * pop (remove) the top of the stack
  * returns the data of top if the stack is not empty
    else returns -1
*/
int pop_ll(stack_ll *stack_ref) {
  if(is_empty_ll(*stack_ref)) log_message(UNDERFLOW);
  else {
    node* to_delete_node = stack_ref->top; // save the old top to delete it later
    int popped_data = to_delete_node->data; // save the data that will be popped (returned)
    stack_ref->top = stack_ref->top->next; // the new top will be next node 
    free(to_delete_node); // deleting the old top
    stack_ref->stack_count-- ;
    return popped_data;
  }
  return -1;
}

int get_top_ll(stack_ll stack) {
  return stack.top->data;
}

#endif
