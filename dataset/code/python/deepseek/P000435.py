def count_occurrences(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    target = int(input())
    print(count_occurrences(arr, target))

if __name__ == "__main__":
    main()