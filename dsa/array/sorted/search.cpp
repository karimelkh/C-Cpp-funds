#include <iostream>
using namespace std;

/*
  * search for the target in the array using the binary search algorithm
  * returns the index of the target if exist else returns -1
*/
int search_bin(int arr[], int index_of_last, int target) {
  int beg = 0, end = index_of_last, mid;
  while(beg <= end) {
    mid = (beg + end) / 2; // Calculate the middle index of the current search range.
    if(arr[mid] > target) end = mid - 1; // adjust `end` to search the lower half of the current range.
    else if(arr[mid] < target) beg = mid + 1; // adjust `beg` to search the upper half of the current range.
    else return mid; // target found at index `mid`.
  }
  return -1; // target not found
}

int main() {
  int arr[10] = {10, 11, 12, 15, 17, 19, 30, 31, 41, 45};

  int index = search_bin(arr, 10, 55); // search for 55
  index == -1 ? cout << "Target not found." << endl : cout << "the index of " << arr[index] << " is: " << index << endl;
  // output: Target not found.

  index = search_bin(arr, 10, 19); // search for 19
  index == -1 ? cout << "Target not found." << endl : cout << "the index of " << arr[index] << " is: " << index << endl;
  // output: the index of 19 is: 5

  return 0;
}
