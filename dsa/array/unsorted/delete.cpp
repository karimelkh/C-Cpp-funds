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

int delete_at(int arr[], int size, int pos) {
  for(int i = pos; i < size; i++)
    arr[i] = arr[i + 1];

  return size - 1;
}

int main() {
  int arr[20] = {21, 9, 6, 11, 5};
  int n = 4;
  print_arr(arr, 20);
  n = delete_at(arr, n, 4);
  print_arr(arr, 20);
  n = delete_at(arr, n, 0);
  print_arr(arr, 20);
  return 0;
}
