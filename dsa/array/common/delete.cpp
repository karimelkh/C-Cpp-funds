#include <iostream>
#include "arr.h" // import the arr.h which have the print_arr function

using namespace std;

void print_arr(int, int);

/*
  * delete the element at the giving index
  * returns the index of new last element
*/
int delete_at(int arr[], int size, int pos) {
  // starts from the giving index (pos). ends at the last index.
  for(int i = pos; i < size; i++)
    arr[i] = arr[i + 1]; // the current element takes the value the next one
  return size - 1; // return the new size (or the index of the new last element)
}

int main() {
  int arr[20] = {21, 9, 6, 11, 5};
  int n = 4; // indecates the index of the last element

  print_arr(arr, n); // output: 21 9 6 11

  n = delete_at(arr, n, n); // delete the last element
  print_arr(arr, n); // output: 21 9 6

  n = delete_at(arr, n, 0); // delete the 1st element
  print_arr(arr, n); // output: 9 6

  return 0;
}
