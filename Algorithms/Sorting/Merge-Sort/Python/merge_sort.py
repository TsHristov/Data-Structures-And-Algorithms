def merge(arr, left, middle, right):
    count_left  = middle - left + 1 # count of elements in left half
    count_right = right - middle    # count of elements in right half

    left_subarray  = []
    right_subarray = []
    
    for i in range(0, count_left):
        left_subarray.append(arr[left + i])
    for j in range(0, count_right):
        right_subarray.append(arr[middle + 1 + j])

    # Merge the temporary arrays:
    i = 0    # Initial index of left subarray
    j = 0    # Initial index of right subarray
    k = left # Initial index of merged subarray
    while i < count_left and j < count_right:
        if left_subarray[i] <= right_subarray[j]:
            arr[k] = left_subarray[i]
            i += 1
        else:
            arr[k] = right_subarray[j]
            j += 1
        k += 1

    # Copy the remaining elements of L, if there are any:
    while i < count_left:
        arr[k] = left_subarray[i]
        i += 1
        k += 1

    while j < count_right:
        arr[k] = right_subarray[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        middle = (left + right) // 2
        merge_sort(arr, left, middle)
        merge_sort(arr, middle + 1, right)
        merge(arr, left, middle, right)

def main():
    arr = [int(x) for x in input().split()]
    merge_sort(arr, 0, len(arr) - 1)
    print(arr)
    
if __name__ == "__main__":
    main()
