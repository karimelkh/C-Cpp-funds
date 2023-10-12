#include <iostream>
#include "../common/arr.h" // import arr.h that includes print_arr and type_of_sort functions

using namespace std;

void print_arr(int, int, int, int);

int type_of_sort(int, int);

/*
  * insert the value in ascendent array
  * returns the new size if the inserting was successful
  * else the returns old size
*/
int insert_asc(int arr[], int capacity, int size, int value) {
  if(size >= capacity) return size;
  int pos = 0;
  
  // loop until find the appropriate position
  while(pos < size) {
    if(arr[pos] >= value) break;
    pos++ ;
  }
  // shift all the elements after pos to the right
  for(int i = size - 1; i >= pos; i--)
    arr[i + 1] = arr[i];
  arr[pos] = value;
  return size + 1;
}

int main() {
  int arr[10] = {1, 2, 4, 5, 6, 7, 8, 9};
  int size = 8;

  cout << "before           : ";
  print_arr(arr, 10, 0, size - 1); // output: 1 2 4 5 6 7 8 9

  size = insert_asc(arr, 10, size, 3); // insert value 3
  cout << "after inserting 3: ";
  print_arr(arr, 10, 0, size - 1); // output: 1 2 3 4 5 6 7 8 9

  size = insert_asc(arr, 10, size, 4); // insert value 4
  cout << "after inserting 4: ";
  print_arr(arr, 10, 0, size - 1); // output:  1 2 3 4 4 5 6 7 8 9

  return 0;
}
