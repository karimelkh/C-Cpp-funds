/* STACK ARRAY IMPLEMENTATION */

class stack_arr {
	int arr[20];
	int top = -1;

	#define OVERFLOW "stack overflow"
	#define UNDERFLOW "stack underflow"
	#define EMPTY_STACK "stack is empty"

	// log the passed message and break the line
	void log_message(const char* message) {
		std::cout << message << std::endl;
	}

public:

	bool is_empty() {
		return top < 0;
	}

	bool is_full() {
		return top >= 19;
	}

	int get_stack_count() {
		return top + 1;
	}

	// print the element of the stack starting from the top
	void print_stack() {
		if(is_empty()) {
			log_message(EMPTY_STACK);
			return;
		}
		for(int i = top; i > -1; i--)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	// push (add) an element to the stack
	void push(int data) {
		if(is_full()) {
			log_message(OVERFLOW);
			return;
		}
		// increment the top and add the new element
		arr[++top] = data;
	}

	/*
    * pop (remove) the top of the stack
    * returns the data of top if the stack is not empty
      else returns -1
  */
	int pop() {
		if(is_empty()) {
			log_message(UNDERFLOW);
			return -1;
		}
		// decrement the top and return the (old) top data
		return arr[top--];
	}

	int get_top() {
		if(is_empty()) {
			log_message(EMPTY_STACK);
			return -1;
		}
		return arr[top];
	}
};
