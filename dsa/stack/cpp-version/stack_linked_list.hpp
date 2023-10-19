/* STACK LINKED LIST IMPLEMENTATION */

class stack_ll {
  struct node {
    int data;
    node* next;
  };

  node* top = nullptr;
  int stack_count = 0;

	#define UNDERFLOW "stack underflow"
	#define EMPTY_STACK "stack is empty"

  // log the passed message and break the line
	void log_message(const char* message) {
		std::cout << message << std::endl;
	}

public:

  bool is_empty() {
    return top == nullptr;
  }

  node* create_node(int d) {
    return new node{d, nullptr};
  }
 
  // print the element of the stack starting from the top
  void print_stack() {
    if(is_empty()) log_message(EMPTY_STACK);
    else {
      node* current_node = top; // the print process will start from the top
      while(current_node != nullptr) { // loop until the end of the stack
        std::cout << current_node->data << " ";
        current_node = current_node->next; // move to the next node
      }
      std::cout << std::endl;
    }
  }

  int get_stack_count() {
    return stack_count;
  }

  // push (add) an element to the stack
  void push(node* new_node) {
    new_node->next = top; // new_node points to the old top
    top = new_node; // new_node is the new top now
    stack_count++ ;
  }

  /*
    * pop (remove) the top of the stack
    * returns the data of top if the stack is not empty
      else returns -1
  */
  int pop() {
    if(is_empty()) log_message(UNDERFLOW);
    else {
      node* to_delete_node = top; // save the old top to delete it later
      int popped_data = to_delete_node->data; // save the data that will be popped (returned)
      top = top->next; // the new top will be next node 
      delete to_delete_node; // deleting the old top
      stack_count-- ;
      return popped_data;
    }
    return -1;
  }

  int get_top() {
    return top->data;
  }
};
