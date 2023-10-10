#include <iostream>

using namespace std;

// prints the arr elements (e.g., 0 2 9 21)
// optional: set a start (from) and end (to) for the print function
// default: 0 -> size - 1
void print_arr(int arr[], int size, int from = 0, int to = -1) {
  if(to == -1)
    to = size - 1;
  else if(to >= size)
    return;

  for(int i = from; i <= to; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Insert at the end of the array
// n represent the real size of the array
// append return the n+1 if the insertion was successful
// else returns n
int append(int arr[], int capacity, int n, int value) {
  if(n >= capacity)
    return n;

  arr[n] = value;
  return n + 1;
}

// Insert at a specific index
// insert the value at the giving index
// and shifts the next elements to the right
// insert returns n+1 if the insertion was successful
// else returns n
int insert(int arr[], int capacity, int n, int pos, int value) {
  if(n >= capacity)
    return n;

  for(int i = n; i >= pos; i--)
    arr[i] = arr[i - 1];

  arr[pos] = value;

  return n + 1;
}

int main() {
  int arr[20] = {9, 1, 8, 5, 3, 2};
  int index = 6, value = 26, value1 = 50;
  int capacity = sizeof(arr) / sizeof(int);
  print_arr(arr, capacity);
  index = append(arr, capacity, index, value);
  print_arr(arr, capacity);
  index = append(arr, capacity, index, value1);
  print_arr(arr, capacity);
  index = insert(arr, capacity, index, 0, 21);
  cout << "endl" << '\n';
  print_arr(arr, capacity, 4, 19);
  print_arr(arr, capacity, 2, capacity);
  print_arr(arr, capacity, 2, 6);
  print_arr(arr, capacity, 2, capacity - 1);
  return 0;
}