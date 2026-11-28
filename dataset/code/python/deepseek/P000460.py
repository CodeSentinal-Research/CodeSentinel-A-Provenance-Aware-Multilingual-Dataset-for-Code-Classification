def find_target(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < arr[mid + 1]:
            if arr[mid] < target and target < arr[mid + 1]:
                left = mid + 1
            else:
                right = mid - 1
        else:
            if arr[mid] < target and target < arr[mid + 1]:
                left = mid + 1
            else:
                right = mid - 1
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    target = int(input().strip())
    print(find_target(arr, target))

if __name__ == "__main__":
    main()