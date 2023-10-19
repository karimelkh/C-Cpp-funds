/* STACK ARRAY IMPLEMENTATION (C VERSION) */

#ifndef STACK_ARR_H
#define STACK_ARR_H

#define OVERFLOW "stack overflow"
#define UNDERFLOW "stack underflow"
#define EMPTY_STACK "stack is empty"

struct S {
	int arr[20];
	int top;
};

typedef struct S stack_arr;

// log the passed message and break the line
void log_message(const char* message) {
  printf("%s\n", message);
}

bool is_empty(stack_arr stack) {
	return stack.top < 0;
}

bool is_full(stack_arr stack) {
	return stack.top >= 19;
}

int get_stack_count(stack_arr stack) {
	return stack.top + 1;
}

// print the element of the stack starting from the top
void print_stack(stack_arr stack) {
	if(is_empty(stack)) {
		log_message(EMPTY_STACK);
		return;
	}
	for(int i = stack.top; i > -1; i--)
    printf("%d ", stack.arr[i]);
  printf("\n");
}

// push (add) an element to the stack
void push(stack_arr* stack_ref, int data) {
	if(is_full(*stack_ref)) {
		log_message(OVERFLOW);
		return;
	}
	// increment the top and add the new element
	stack_ref->arr[++(stack_ref->top)] = data;
}

/*
	* pop (remove) the top of the stack
	* returns the data of top if the stack is not empty
		else returns -1
*/
int pop(stack_arr* stack_ref) {
	if(is_empty(*stack_ref)) {
		log_message(UNDERFLOW);
		return -1;
	}
	// decrement the top and return the (old) top data
	return stack_ref->arr[stack_ref->top--];
}

int get_top(stack_arr stack) {
	if(is_empty(stack)) {
		log_message(EMPTY_STACK);
		return -1;
	}
	return stack.arr[stack.top];
}

#endif
