#include <iostream>
using namespace std;

void merge(int *arr, int left, int middle, int right) {
  int count_left  = middle - left + 1;
  int count_right = right - middle;

  int *left_subarray  = new (nothrow) int[count_left];
  int *right_subarray = new (nothrow) int[count_right];

  for(int i=0; i < count_left; i++) {
    left_subarray[i] = arr[left + i];
  }

  for(int i=0; i < count_right; i++) {
    right_subarray[i] = arr[middle + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = left;
  while(i < count_left && j < count_right){
    if(left_subarray[i] <= right_subarray[j]){
      arr[k++] = left_subarray[i++];
    } else {
      arr[k++] = right_subarray[j++];
    }
  }

  while(i < count_left) {
    arr[k++] = left_subarray[i++];
  }

  while(j < count_right) {
    arr[k++] = right_subarray[j++];
  }

  delete[] left_subarray;
  delete[] right_subarray;
}

void merge_sort(int *arr, int left, int right) {
  if(left < right){
    int middle = (left + right) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
  }
}

int main(){
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size  = sizeof(arr)/sizeof(arr[0]);
  merge_sort(arr, 0, size - 1);

  for(int i=0; i < size; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
