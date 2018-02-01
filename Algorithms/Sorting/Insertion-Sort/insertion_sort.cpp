#include <iostream>
using namespace std;

void insertion_sort(int *, const int);
void fill_array(int *, const int);
void print_array(int *, const int);

int main() {
  const int SIZE = 5;
  int arr[SIZE];

  fill_array(arr, SIZE);
  insertion_sort(arr, SIZE);
  print_array(arr, SIZE);
  
  return 0;
}

void insertion_sort(int *arr, const int n){
  int key, j;
  for(int i = 1; i < n; i++){
    key = arr[i];
    for(j = i; arr[j-1] > key && j > 0; j--){
      arr[j] = arr[j-1];
    }
    arr[j] = key;
  }
}

void fill_array(int *arr, const int n){
  for(int i=0; i < n; i++){
    cin >> arr[i];
  }  
}

void print_array(int *arr, const int n){
  for(int i=0; i < n; i++){
    cout << arr[i] << " ";
  }
}
