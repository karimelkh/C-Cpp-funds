#include <iostream>
using namespace std;

int search_bin(int arr[], int index_of_last, int target) {
  int beg = 0, end = index_of_last, mid;
  while(beg <= end) {
    mid = (beg + end) / 2;
    if(arr[mid] > target) end = mid - 1;
    else if(arr[mid] < target) beg = mid + 1;
    else return mid;
  }
  return -1;
}

int main() {
  int arr[10] = {10, 11, 12, 15, 17, 19, 30, 31, 41, 45};

  int index = search_bin(arr, 10, 55);
  if(index != -1)
    cout << "the index of " << arr[index] << " is: " << index << endl;
  else
    cout << "Target not found." << endl;

  index = search_bin(arr, 10, 19);
  if(index != -1)
    cout << "the index of " << arr[index] << " is: " << index << endl;
  else
    cout << "Target not found." << endl;
  return 0;
}
