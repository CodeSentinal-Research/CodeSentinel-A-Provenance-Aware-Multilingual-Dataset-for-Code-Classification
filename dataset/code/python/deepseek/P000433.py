def binary_search_first_occurrence(arr, target):
    start = 0
    end = len(arr) - 1
    first_occurrence = -1

    while start <= end:
        mid = start + (end - start) // 2

        if arr[mid] == target:
            first_occurrence = mid
            end = mid - 1  
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return first_occurrence

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    target = int(input().strip())

    result = binary_search_first_occurrence(arr, target)
    print(result)

if __name__ == "__main__":
    main()