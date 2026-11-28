Here's the code:

def find_ceiling(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def main():
    N = int(input().strip())
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))
    index = find_ceiling(arr, target)
    if index != -1:
        print(index)
    else:
        print('-1')

if __name__ == "__main__":
    main()

In this code, the function `find_ceiling` is implemented to find the ceiling of a target in a sorted array. It uses binary search to find the target's ceiling in the array. If the target is found, its index is returned. If not, -1 is returned.

The `main` function is the entry point of the program. It first reads the number of elements and the target from the standard input, then reads the sorted array from the standard input. It then calls `find_ceiling` to find the ceiling of the target and prints the result.