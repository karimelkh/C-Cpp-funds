#include <iostream>
using namespace std;

int find(int value, int arr[], int size) {
  for(int i = 0; i < size; i++)
    if(arr[i] == value) return i;
  return -1;
}

int main() {
  int arr[10] = {9, 4, 17, 22};
  int n = 4;
  cout << "index of 22 is: " << find(22, arr, n) << endl;
  return 0;
}
