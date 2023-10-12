#include <iostream>
#include "../common/arr.h"

using namespace std;

void print_arr(int, int);

void switch_value(int, int, int);

void sort_asc(int arr[], int size) {
  int min;
  for(int i=0; i<size; i++) {
    min = i;
    for(int j=i+1; j<size; j++)
      if(arr[j] < arr[min]) min = j;
    switch_value(arr, min, i);
  }
}

void sort_desc(int arr[], int size) {
  int max;
  for(int i=0; i<size; i++) {
    max = i;
    for(int j=i+1; j<size; j++)
      if(arr[j] > arr[max]) max = j;
    switch_value(arr, max, i);
  }
}

int main() {
  int arr[5] = {7, 5, 4, 9, 6};
  print_arr(arr, 5);
  sort_asc(arr, 5);
  print_arr(arr, 5);
  sort_desc(arr, 5);
  print_arr(arr, 5);
  return 0;
}
