def search_in_rotated_array(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] == arr[right]:
            right = mid - 1
        elif arr[mid] == arr[left]:
            left = mid + 1
        else:
            if target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
    return -1

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    target = int(input().strip())
    print(search_in_rotated_array(arr, target))

if __name__ == "__main__":
    main()