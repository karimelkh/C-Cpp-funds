/*
	Stacks are an abstract data type (ADT) characterized by a LIFO (last in first out) property.
	Items are added and removed from the top. Examples include dinner plates and the Tower of Hanoi.
	They restrict insertion and deletion to one end.
*/

#include <iostream>
#include "stack_arr.hpp" // includes stack_arr object
#include "./stack_linked_list.hpp"  // includes stack_ll object

using namespace std;

int main() {
	// ARRAY TESTS
	cout << "ARRAY" << endl;

	stack_arr SA;

	for(int i=0; i<3; i++)
		SA.push(i);

	cout << "stack count: " << SA.get_stack_count() << endl;
	cout << "top: " << SA.get_top() << endl;

	cout << "stack: ";
	SA.print_stack();

	cout << SA.pop() << " popped" << endl;
	cout << SA.pop() << " popped" << endl;
	cout << SA.pop() << " popped" << endl;
	cout << SA.pop() << " popped" << endl;

	cout << "stack: ";
	SA.print_stack();

	cout << "-----------------------" << endl;

	// LINKED LIST TESTS

	cout << "LINKED LIST" << endl;

	stack_ll SL;

	for(int i=0; i<3; i++)
		SL.push(SL.create_node(i));

	cout << "stack count: " << SL.get_stack_count() << endl;
	cout << "top: " << SL.get_top() << endl;

	cout << "stack: ";
	SL.print_stack();

	cout << SL.pop() << " popped" << endl;
	cout << SL.pop() << " popped" << endl;
	cout << SL.pop() << " popped" << endl;
	cout << SL.pop() << " popped" << endl;

	cout << "stack: ";
	SL.print_stack();

	return 0;
}