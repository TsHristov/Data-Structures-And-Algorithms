def insertion_sort(arr):
    size = len(arr)
    for i in range(1,size):
        key = arr[i]
        j = i
        while(j > 0 and arr[j-1] > key):
            arr[j] = arr[j-1]
            j-=1
        arr[j] = key 

def main():
    arr = [int(x) for x in input().split()]
    insertion_sort(arr)
    print(arr)

if __name__ == "__main__":
    main()
    
