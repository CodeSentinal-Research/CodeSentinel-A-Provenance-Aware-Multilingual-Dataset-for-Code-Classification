Here's the Python code for the problem:

def findKthElement(arr1, arr2, k):
    if not arr1:
        return arr2[k]
    if not arr2:
        return arr1[k]
    if k == 1:
        return min(arr1[0], arr2[0])

    i = min(k // 2, len(arr1)) - 1
    j = min(k // 2, len(arr2)) - 1

    if arr1[i] < arr2[j]:
        return findKthElement(arr1[i + 1:], arr2, k - i - 1)
    else:
        return findKthElement(arr1, arr2[j + 1:], k - j - 1)

def main():
    m, n, k = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    print(findKthElement(arr1, arr2, k))

if __name__ == "__main__":
    main()

This program first reads the size of both arrays and the kth element to find. It then reads the arrays themselves. The `findKthElement` function is a recursive function that finds the kth element in the merged sorted arrays. It uses a divide and conquer strategy to find the kth element. The time complexity of this algorithm is O(log(min(M, N))).