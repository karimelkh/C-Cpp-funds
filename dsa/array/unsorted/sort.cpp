#include <iostream>
#include "../common/arr.h" // import the arr.h that includes the print_arr and switch_values functions

using namespace std;

void print_arr(int, int);

void switch_value(int, int, int);


// sort the giving array ascendent using Selection Sort algorithm
void sort_asc(int arr[], int size) {
  int index_min; // indecate the index of the minimum value
  for(int i=0; i<size; i++) {
    index_min = i; // set the the first element as the minimum
    for(int j=i+1; j<size; j++) // loop through the unsorted part of the array
      if(arr[j] < arr[index_min]) index_min = j; // if the current element < the current minimum element => change the value of index_min
    switch_value(arr, index_min, i); // switch the values of the first index of the unsorted part and the minimum element
  }
}

// sort the giving array descendent using Selection Sort algorithm
void sort_desc(int arr[], int size) {
  int index_max; // indecate the index of the maximum value
  for(int i=0; i<size; i++) {
    index_max = i; // set the the first element as the maximum
    for(int j=i+1; j<size; j++) // loop through the unsorted part of the array
      if(arr[j] > arr[index_max]) index_max = j; // if the current element > the current minimum element => chage the value of index_max
    switch_value(arr, index_max, i); // switch the values of the first index of the unsorted part and the maximum element
  }
}

int main() {
  int arr[5] = {7, 5, 4, 9, 6};
  print_arr(arr, 5); // output: 7 5 4 9 6

  sort_asc(arr, 5); // sort arr ascendent
  print_arr(arr, 5); // output: 4 5 6 7 9

  sort_desc(arr, 5); // sort arr descendent
  print_arr(arr, 5); // output: 9 7 6 5 4
  return 0;
}
