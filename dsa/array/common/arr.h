/*
  * prints the arr elements (e.g., 0 2 9 21)
  * optional: set a start (from) and end (to) for the print function
  * default: 0 -> size - 1
*/
void print_arr(int arr[], int size, int from = 0, int to = -1) {
  // if the value of `to` was not passed. It will takes the default value.
  // The default value for `to` is the size of the array
  if(to == -1 || to >= size) to = size - 1;

  // the loop starts from `from` variable (hh funny 🤓)
  // and ends and `to` variable
  for(int i = from; i <= to; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

/*
  * switch the values in the giving indeces in an array
  * arr: the array whose values will switch.
  * ia and ib: are the indeces of the to-switch values
*/
void switch_value(int arr[], int ia, int ib) {
  // if the indeces and the values was equal. There is no need to switch.
  if(ia == ib || arr[ia] == arr[ib]) return;
  
  // switch using extra variable (temp)
  int temp = arr[ia];
  arr[ia] = arr[ib];
  arr[ib] = temp;
}

/*
  The type_of_sort function takes as an argument:
    * arr : the array that the function will tests.
    * last_index : the index of last element in the array.

  and returns:
    * 1 : if the array is sorted ascending.
    * -1 : if the array is sorted descending.
    * 0 : if the array is not sorted.

*/
int type_of_sort(int arr[], int last_index) {
  // if the array conatains one element => arr is not sorted
  if(last_index <= 0) return 0;

  // initial truty values for `asc` and `desc`
  int asc = 1, desc = 1;

  // loop through the array
  for(int i = 0; i < last_index; i++) {
    // if there is at least two contiguous elements that 1st < 2nd => arr is not desc
    if(arr[i] < arr[i + 1]) desc = 0;

    // if there is at least two contiguous elements that 1st > 2nd => arr is not asc
    else if(arr[i] > arr[i + 1]) asc = 0;

    // if arr not asc or desc => arr is not sorted
    else if(!(asc || desc)) return 0;
  }
  if(asc) return 1;
  if(desc) return -1;
  // extra return that if it's not asc or desc so it's not sorted
  return 0;
}
