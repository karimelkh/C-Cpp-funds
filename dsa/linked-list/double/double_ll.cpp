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
    node* current_node = head;
    cout << "head -> ";
    while(current_node->next != NULL) {
      cout << current_node->data << " <=> ";
      current_node = current_node->next;
    }
    cout << current_node->data << " -> NULL" << endl;
  }

  node* create_node(int d) {
    return new node{d, NULL, NULL};
  }

  void insert_beg(node* new_node) {
    if(head->next != NULL) head->next->prev = new_node;
    new_node->next = head;
    head = new_node;
    size++ ;
  }

  void insert_end(node* new_node) {
    if(is_empty()) return;
    node* last_node = head;
    while(last_node->next != NULL)
      last_node = last_node->next;
    new_node->prev = last_node;
    last_node->next = new_node;
    size++ ;
  }

  void inser_at(node* new_node, int pos) {
    if(is_empty()) return;
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
  }

  void delete_at() {
    if(is_empty()) return;
  }


};

int main() {
  double_list list;
  list.insert_beg(list.create_node(2));
  // list.insert_beg(list.create_node(1));
  cout << list.get_size() << endl;


}
