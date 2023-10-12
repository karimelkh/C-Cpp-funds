#include <iostream>
using namespace std;

/*
  * find the value in the array that have the giving size
  * returns the index of the value if exist else returns -1
*/
int find(int value, int arr[], int size) { 
  for(int i = 0; i < size; i++)
    if(arr[i] == value) return i;
  return -1;
}

int main() {
  int arr[10] = {9, 4, 17, 22};
  int size = 4;
  cout << "index of 17 is: " << find(17, arr, size) << endl;
  return 0;
}
