def binary_search_last_occurrence(arr, target):
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            result = mid
            left = mid + 1
        else:
            right = mid - 1

    return result

def main():
    N, target = map(int, input().split())
    arr = list(map(int, input().split()))

    print(binary_search_last_occurrence(arr, target))

if __name__ == "__main__":
    main()