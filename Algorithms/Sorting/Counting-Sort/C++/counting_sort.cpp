#include <iostream>
using namespace std;

void counting_sort(int *arr, const int size, const int MAX_VALUE=10){
  int counts[MAX_VALUE] = { 0 };

  int i, j;
  for(i = 0; i < size; i++){
    counts[arr[i]]++;
  }
  
  for(i = j = 0; i < MAX_VALUE; i++){
    while(counts[i]--){
      arr[j++] = i;
    }
  }
}

int main(){
  int arr[] = {1,4,1,2,7,5,2};
  counting_sort(arr,7);

  for(int i = 0; i < 7; i++){
    cout << arr[i] << " ";
  }
  
  return 0;
}
