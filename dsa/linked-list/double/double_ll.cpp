#include <iostream>
using namespace std;

#define EMPTY_LIST_ERROR "The list is empty."
#define INVALID_POS_ERROR "Invalid position."

class double_list {
  struct node {
    int data;
    node* next;
    node* prev;
  };
  node* head = NULL;
  int size = 0;

public:

  int get_size() {
    return size;
  }

  bool is_empty() {
    if(size == 0) return true;
    return false;
  }

  void print_list() {
    if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
    else {
      node* current_node = head;
      cout << "head -> ";
      while(current_node->next != NULL) {
        cout << current_node->data << " <=> ";
        current_node = current_node->next;
      }
      cout << current_node->data << " -> NULL" << endl;
    }
  }

  node* create_node(int d) {
    return new node{d, NULL, NULL};
  }

  void insert_beg(node* new_node) {
    if(is_empty()) {
      head = new_node;
      size++ ;
      return;
    }
    if(head->next != NULL) head->next->prev = new_node;
    new_node->next = head;
    head = new_node;
    size++ ;
  }

  void insert_end(node* new_node) {
    if(is_empty()) insert_beg(new_node);
    else {
      node* last_node = head;
      while(last_node->next != NULL)
        last_node = last_node->next;
      new_node->prev = last_node;
      last_node->next = new_node;
      size++ ;
    }
  }

  void insert_at(node* new_node, int pos) {
    if(pos == 1) insert_beg(new_node);
    else if(pos == size + 1) insert_end(new_node);
    else if(pos > size + 1 || pos < 1) cout << INVALID_POS_ERROR << endl;
    else {
      node* node_at_pos = head;
      int i = 1;
      while(i < pos) {
        node_at_pos = node_at_pos->next;
        i++ ;
      }
      new_node->next = node_at_pos;
      new_node->prev = node_at_pos->prev;
      if(node_at_pos->prev != NULL) node_at_pos->prev->next = new_node;
      else head = new_node;
      node_at_pos->prev = new_node;
      size++ ;
    }
  }

  void delete_beg() {
    if(is_empty()) return;
    node* first_node = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    delete first_node;
    size-- ;
  }

  void delete_end() {
    if(is_empty()) return;
    node* last_node = head;
    while(last_node->next != NULL)
      last_node = last_node->next;
    if(last_node->prev != NULL) last_node->prev->next = NULL;
    else head = NULL;
    size-- ;
  }

  void delete_at(int pos) {
    if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
    else if(pos > size || pos < 1) cout << INVALID_POS_ERROR << endl;
    else if(pos == 1) delete_beg();
    else if(pos == size) delete_end();
    else {
      node* node_at_pos = head;
      int i = 1;
      while(i < pos) {
        node_at_pos = node_at_pos->next;
        i++ ;
      }
      node_at_pos->prev->next = node_at_pos->next;
      node_at_pos->next->prev = node_at_pos->prev;
      delete node_at_pos;
      size-- ;
    }
  }

  void reverse_list() {
    if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
    else if(size == 1) return;
    else {
      node* current_node = head;
      node* next_node;
      while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = current_node->prev;
        current_node->prev = next_node;
        if(current_node->prev == NULL) head = current_node;
        current_node = current_node->prev;
      }
    }
  }
};

int main() {
  double_list list;  
  
  // inserting test
  list.insert_at(list.create_node(1), 1);
  list.insert_at(list.create_node(2), 2);
  list.insert_at(list.create_node(3), 2);
  cout << "after inserting: " << endl;
  cout << "Size: " << list.get_size() << endl;
  list.print_list();

  cout << "\n";

  // deleting test
  list.delete_at(1);
  cout << "after delete pos 1: " << endl;
  cout << "Size: " << list.get_size() << endl;
  list.print_list();

  cout << "\n";

  // reversing test
  list.reverse_list();
  cout << "after reverse: " << endl;
  cout << "Size: " << list.get_size() << endl;
  list.print_list();

  return 0;
}