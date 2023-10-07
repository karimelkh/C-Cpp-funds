#include <iostream>
using namespace std;

void print_arr(int arr[], int size, int from = 0, int to = -1) {
  if(to == -1)
    to = size - 1;
  else if(to >= size)
    return;

  for(int i = from; i <= to; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int type_of_sort(int arr[], int size) {
  if(size == 1) return 0;
  
  int i = 0;
  while(1) {
    if(arr[i] != arr[i+1]) break;
    if(++i == size) return 0;
  }
  
  if(arr[i] < arr[i+1]) return 1;
  if(arr[i] > arr[i+1]) return -1;
  return 0;
}

int insert_asc(int arr[], int capacity, int n, int value) {
  if(n + 1 >= capacity) return n;

  int pos = 0;
  while(pos <= n) {
    if(arr[pos] >= value) break;
    pos++ ;
  }
  
  for(int i = n; i >= pos; i--)
    arr[i + 1] = arr[i];
  
  arr[pos] = value;
  return n + 1;
}

// int insert_value(int arr[], int capacity, int size, int value) {
//   if(type_of_sort(arr, size) == 1) return insert_asc(arr, capacity, size, value);
//   // else if(type_of_sort(arr, size) == -1) insert_desc(arr, capacity, size, value);
//   else return size;
// }

int main() {
  int arr[10] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
  int n = 8;
  cout << "before           : ";
  print_arr(arr, 10);
  n = insert_asc(arr, 10, n, 3);
  cout << "after inserting 3: ";
  print_arr(arr, 10);
  n = insert_asc(arr, 10, n, 4);
  cout << "after inserting 4: ";
  print_arr(arr, 10);
  return 0;
}