
def counting_sort(arr, MAX_VALUE=10):
    # 0. Initialize counts array with zeroes:
    cnt = [0] * MAX_VALUE
    # 1. Count each elements occurences:
    for i in arr:
        cnt[i] += 1
    # 2. Generate sorted array:
    j = 0
    for i in range(0, MAX_VALUE):
        while(cnt[i]):
            arr[j] = i
            j += 1
            cnt[i] -= 1
    return arr

def main():
    arr = [int(x) for x in input().split()]
    counting_sort(arr,MAX_VALUE=10)
    print(arr)
    
if __name__ == "__main__":
    main()
