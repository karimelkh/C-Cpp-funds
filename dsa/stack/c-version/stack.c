#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_arr.h" // includes stack_arr object
#include "./stack_linked_list.h"  // includes stack_ll object

int main() {
	// ARRAY TESTS
	log_message("ARRAY");

	stack_arr array_stack;
	array_stack.top = -1;

	for(int i=0; i<3; i++)
		push(&array_stack, i);

	printf("stack count: %d\n", get_stack_count(array_stack));
	printf("top: %d\n", get_top(array_stack));

	printf("stack: ");
	print_stack(array_stack);

	printf("%d popped\n", pop(&array_stack));
	printf("%d popped\n", pop(&array_stack));
	printf("%d popped\n", pop(&array_stack));
	printf("%d popped\n", pop(&array_stack));

	printf("stack: ");
	print_stack(array_stack);

	printf("-----------------------\n");

	// LINKED LIST TESTS

	log_message("LINKED LIST");

	stack_ll liked_list_stack;

	liked_list_stack.top = NULL;
	liked_list_stack.stack_count = 0;

	for(int i=0; i<3; i++)
		push_ll(&liked_list_stack, create_node(i));

	printf("stack count: %d\n", get_stack_count_ll(liked_list_stack));

	if (!is_empty_ll(liked_list_stack))
		printf("top: %d\n", get_top_ll(liked_list_stack));

	else log_message(EMPTY_STACK);


	printf("stack: ");
	print_stack_ll(liked_list_stack);

	printf("%d popped\n", pop_ll(&liked_list_stack));
	printf("%d popped\n", pop_ll(&liked_list_stack));
	printf("%d popped\n", pop_ll(&liked_list_stack));
	printf("%d popped\n", pop_ll(&liked_list_stack));

	printf("stack: ");
	print_stack_ll(liked_list_stack);

	return 0;
}
