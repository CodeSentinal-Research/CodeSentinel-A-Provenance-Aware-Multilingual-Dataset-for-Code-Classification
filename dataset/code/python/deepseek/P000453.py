Here is the code:

def find_fixed_point(arr):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < mid:
            low = mid + 1
        elif arr[mid] > mid:
            high = mid - 1
        else:
            return mid
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_fixed_point(arr))

if __name__ == '__main__':
    main()
This program uses binary search to find the fixed point in the array. The fixed point is the index where the element equals its index. If no fixed point is found, it returns -1. The input is handled in the main function.