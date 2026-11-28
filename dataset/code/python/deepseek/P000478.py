def binary_search(arr, n, c):
    arr.sort()
    low = 0
    high = arr[-1] - arr[0]
    while low < high:
        mid = (low + high) // 2
        cows = 1
        stall = arr[0]
        for i in range(1, n):
            if arr[i] - stall >= mid:
                cows += 1
                stall = arr[i]
        if cows >= c:
            low = mid + 1
        else:
            high = mid
    return low - 1

def main():
    n, c = map(int, input().split())
    arr = list(map(int, input().split()))
    print(binary_search(arr, n, c))

if __name__ == "__main__":
    main()