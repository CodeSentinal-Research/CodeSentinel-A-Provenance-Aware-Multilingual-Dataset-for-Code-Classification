Here is the Python code:

def peakIndexInMountainArray(A):
    left, right = 0, len(A) - 1

    while left < right:
        mid = (left + right) // 2
        if A[mid] < A[mid + 1]:
            left = mid + 1
        else:
            right = mid

    return left

def main():
    n = int(input().strip())
    A = list(map(int, input().strip().split()))
    print(peakIndexInMountainArray(A))

if __name__ == '__main__':
    main()

This program uses binary search to find the peak index in a mountain array. The binary search algorithm works by dividing the array into two halves and checking if the middle element is greater than its neighbours. If it is, then the peak element would be in the right half. If not, then the peak element would be in the left half. The process is repeated until the peak element is found.