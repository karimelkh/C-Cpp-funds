#include <iostream>
#include "arr.h"

using namespace std;

void print_arr(int, int, int, int);
int type_of_sort(int, int);

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
