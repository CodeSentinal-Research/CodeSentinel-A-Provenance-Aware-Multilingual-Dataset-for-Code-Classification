def find_peak(arr):
    n = len(arr)
    for i in range(1, n-1):
        if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
            return i
    return -1

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_peak(arr))

if __name__ == "__main__":
    main()