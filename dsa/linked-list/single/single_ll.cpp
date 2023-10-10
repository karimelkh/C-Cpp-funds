#include <iostream>
using namespace std;

#define EMPTY_LIST_ERROR "The list is empty."
#define INVALID_POS_ERROR "Invalid position."

class single_list {
  struct node {
    int data;
    node* next;
  };
  node* head = NULL;
  int size = 0;

  public:

    bool is_empty() {
      if(size == 0) return true;
      return false;
    }

    int get_size() {
      return size;
    }

    void print_list() {
      if(is_empty()) {
        cout << EMPTY_LIST_ERROR << endl;
        return;
      }
      node* H = head;
      cout << "head -> ";
      while(H != NULL) {
        cout << H->data << " -> ";
        H = H->next;
      }
      cout << "NULL" << endl;
    }

    void print_reverse_list() {
      if(size == 0) return;
      node* H = head;
      int arr[size];
      for(int i=0; i<size; i++) {
        arr[i] = H->data;
        H = H->next;
      }
      cout << "NULL";
      for(int i=size-1; i>=0; i--)
        cout << " <- " << arr[i];
      cout << " <- head" << endl;
    }

    void print_list_rec(node* head) { //
      if(is_empty()) {
        cout << endl;
        return;
      }
      cout << head->data << " ";
      print_list_rec(head->next);
    }

    void print_reverse_list_rec(node* head) { //
      if(size == 0) return;
      print_reverse_list_rec(head->next);
      cout << head->data << " ";
    }

    node* create_node(int d) {
      return new node{d, NULL};
    }

    void insert_beg(node* N) {
      N->next = head;
      head = N;
      size++ ;
    }

    void insert_end(node* N) {
      if(is_empty()) {
        insert_beg(N);
        return;
      }
      node* H = head;
      while(H->next != NULL)
        H = H->next;
      H->next = N;
      N->next = NULL;
      size++ ;
    }

    void insert_at(node* N, int pos) {
      if(pos == 1) insert_beg(N);
      else if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
      else if(pos > size + 1 || pos < 1) cout << INVALID_POS_ERROR << endl;
      else {
        node* H = head;
        int i = 1;
        while(i < pos - 1){
          H = H->next;
          i++ ;
        }
        N->next = H->next;
        H->next = N;
        size++ ;
      }
    }

    void delete_beg() {
      if(is_empty()) return;
      node* first_node = head;
      head = head->next;
      delete first_node;
      size-- ;
    }

    void delete_end() {
      if(is_empty()) return;
      if(size == 1) {
        delete_beg();
        return;
      }
      node* H = head;
      while(H->next->next != NULL)
        H = H->next;
      node* last_node = H->next;
      H->next = NULL;
      delete last_node;
      size-- ;
    }

    void delete_at(int pos) {
      if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
      else if(pos > size || pos < 1) cout << INVALID_POS_ERROR << endl;
      else if(pos == 1) delete_beg();
      else {
        node* tmp = head;
        int i = 1;
        while(i < pos - 1) {
          tmp = tmp->next;
          i++ ;
        }
        node* node_at_pos = tmp->next;
        tmp->next = node_at_pos->next; // or tmp->next->next
        delete node_at_pos;
        size-- ;
      }
    }

    void reverse_list() {
      if(is_empty()) return;
      node *prv = NULL, *cur = head, *nxt;
      while(cur != NULL) {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
      }
      head = prv;
    }

    void reverse_list_rec(node*& head_ref) { //
      if (head_ref == NULL || head_ref->next == NULL) return;
      node* rest = head_ref->next;
      reverse_list_rec(rest);
      head_ref->next->next = head_ref;
      head_ref->next = NULL;
      head_ref = rest;
    }
};

int main() {
  single_list list;
  list.insert_beg(list.create_node(12));

  list.print_list();
  list.reverse_list();
  list.print_list();

  return 0;
}
