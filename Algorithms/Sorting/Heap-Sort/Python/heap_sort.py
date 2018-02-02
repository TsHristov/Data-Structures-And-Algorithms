from math import floor

def parent(i):
    return floor((i-1)/2)

def left_child(i):
    return 2*i + 1

def sift_down(arr, start, end):
    root = start

    while left_child(root) <= end:
        child = left_child(root)
        swap  = root

        if arr[swap] < arr[child]:
            swap = child

        if child + 1 <= end and arr[swap] < arr[child + 1]:
            swap = child + 1

        if swap == root:
            return
        else:
            arr[root], arr[swap] = arr[swap], arr[root]
            root = swap

def heapify(arr, count):
    start = parent(count-1)

    while start >= 0:
        sift_down(arr, start, count - 1)
        start = start - 1

def heap_sort(arr):
    count = len(arr)
    heapify(arr, count)
    end = count - 1
    while end > 0:
        arr[0], arr[end] = arr[end], arr[0]
        end = end - 1
        sift_down(arr, 0, end)

def main():
    arr = [int(x) for x in input().split()]
    heap_sort(arr)
    print(arr)

if __name__ == "__main__":
    main()
