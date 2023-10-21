/*
	queues are an abstract data type (ADT) characterized by a FIFO (first in first out) property.
	Items are added from the top and removed from the end. Examples include queue of people.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_array.h"
#include "queue_liked_list.h"

void log_message(const char* m) {printf("%s\n", m);}

void array_test() {
	log_message("ARRAY TEST");
	printf("\n");

	queue_arr Q;
	init_queue(&Q);

	for (int i=0; i<5; i++) {
		enqueue_arr(&Q, i);
		printf("%d in\n", i);
	}
	printf("\n");

	printf("queue: ");
	print_queue_arr(Q);
	printf("\n");

	printf("%d out\n", dequeue_arr(&Q));
	printf("%d out\n", dequeue_arr(&Q));
	printf("%d out\n", dequeue_arr(&Q));
	printf("\n");

	for (int i=7; i<11; i++) {
		enqueue_arr(&Q, i);
		printf("%d in\n", i);
	}
	printf("\n");

	printf("queue: ");
	print_queue_arr(Q);
	printf("\n");
}

void linked_list_test() {
	log_message("LINKED LIST TEST");
	printf("\n");

	queue_ll Q;
	init_queue_ll(&Q);

	for (int i=0; i<5; i++) {
		enqueue_ll(&Q, i);
		printf("%d in\n", i);
	}
	printf("\n");

	printf("queue: ");
	print_queue_ll(Q);
	printf("\n");

	printf("%d out\n", dequeue_ll(&Q));
	printf("%d out\n", dequeue_ll(&Q));
	printf("%d out\n", dequeue_ll(&Q));
	printf("\n");

	for (int i=7; i<11; i++) {
		enqueue_ll(&Q, i);
		printf("%d in\n", i);
	}
	printf("\n");

	printf("queue: ");
	print_queue_ll(Q);
	printf("\n");
}

int main() {
	char choice;
	int c;
	do {
		printf("Which test do you want to see?\n");
		printf("(a)rray test or (l)inked list test, or (e)xit?");
		fflush(stdin);
		scanf("%c", &choice);
		fflush(stdin);
		switch (choice) {
			case 'a': array_test(); break;
			case 'l': linked_list_test(); break;
			case 'e': exit(1);
			default: printf("Invalid choice, try again. Type 'e' to exit."); break;
		}
	} while(getchar() == '\n');

  return 0;
}
