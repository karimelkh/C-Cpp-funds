#include <iostream>
#include "../common/arr.h" // import the arr.h that includes print_arr function

using namespace std;

void print_arr(int, int);

/*
  * Insert at the end of the array
  * size : representd the "real" size of the array
  * Returns the size + 1 if the insertion was successful
    else returns size
*/
int append(int arr[], int capacity, int size, int value) {
  if(size >= capacity) return size;
  arr[size] = value;
  return size + 1;
}

/*
  * Insert at a specific index
  * insert returns size +1 if the insertion was successful
    else returns size
*/
int insert(int arr[], int capacity, int size, int pos, int value) {
  if(size >= capacity) return size;

  // shift all the elements after pos to the right
  for(int i = size; i >= pos; i--) // starts from the end of the array and ends at the pos
    arr[i] = arr[i - 1]; // give the value of the previous index to the element of the current index
  arr[pos] = value;
  return size + 1;
}

int main() {
  int arr[20] = {9, 1, 8, 5, 3, 2};
  int size = 6;
  int capacity = sizeof(arr) / sizeof(int); // it's like assign 20 to capacity. But I want to do it in that way.
  
  print_arr(arr, capacity, 0, size - 1); // output: 9 1 8 5 3 2

  size = append(arr, capacity, size, 26); // append value 26 to the array
  print_arr(arr, capacity, 0, size - 1); // output: 9 1 8 5 3 2 26

  size = append(arr, capacity, size, 50); // append value 50 to the array
  print_arr(arr, capacity, 0, size - 1); // output: 9 1 8 5 3 2 26 50

  size = insert(arr, capacity, size, 0, 21); // insert the value 21 at the front of the array
  print_arr(arr, capacity, 0, size - 1); // output: 21 9 1 8 5 3 2 26 50

  return 0;
}
