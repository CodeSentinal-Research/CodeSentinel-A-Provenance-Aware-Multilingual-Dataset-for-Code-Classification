def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    target = int(input().strip())

    result = binary_search(arr, target)

    print(result)

if __name__ == "__main__":
    main()