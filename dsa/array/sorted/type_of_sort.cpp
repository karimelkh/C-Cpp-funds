#include <iostream>
using namespace std;

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

int main() {
  int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  cout << type_of_sort(arr1, 10) << endl;
  cout << type_of_sort(arr2, 10) << endl;
  return 0;
}