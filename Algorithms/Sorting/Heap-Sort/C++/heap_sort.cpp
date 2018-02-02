#include <iostream>
#include <math.h>
using namespace std;

int left_child(int root) {
  return 2*root + 1;
}

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void sift_down(int *arr, int start, int end) {
  int root = start;

  while(left_child(root) <= end) {
    int child   = left_child(root);
    int to_swap = root;
    
    if(arr[to_swap] < arr[child]) {
      to_swap = child; 
    }
    
    if((child + 1 <= end) && (arr[to_swap] < arr[child + 1])) {
      to_swap = child + 1;
    }
    
    if(to_swap == root){
      return;
    } else {
      swap(arr[root], arr[to_swap]);
      root = to_swap;
    }
  }
}

void heapify(int *arr, int size){
  int start = floor((size - 1)/2);

  while(start >= 0) {
    sift_down(arr, start, size - 1);
    start--;
  }
}

void heap_sort(int *arr, int size){
  heapify(arr, size);
  int end = size - 1;
  while(end > 0){
    // Break Heap property:
    swap(arr[0], arr[end]);
    end--;
    // Restore Heap property:
    sift_down(arr, 0, end);
  }
}

int main(){
  int arr[] = {6,5,3,1,8,7,2,4,19,-5,10,27};

  int size = sizeof(arr) / sizeof(arr[0]);

  heap_sort(arr, size);
  
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
