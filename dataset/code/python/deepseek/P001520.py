Here is the Python code:

def maxChunksToSorted(arr):
    n = len(arr)
    leftMax = [0]*n
    leftMax[0] = arr[0]

    for i in range(1, n):
        leftMax[i] = max(leftMax[i-1], arr[i])

    rightMin = [0]*n
    rightMin[-1] = arr[-1]

    for i in range(n-2, -1, -1):
        rightMin[i] = min(rightMin[i+1], arr[i])

    count = 0
    for i in range(n-1):
        if leftMax[i] <= rightMin[i+1]:
            count += 1
    return count+1

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    print(maxChunksToSorted(arr))

if __name__ == '__main__':
    main()

This code first calculates the maximum element on the left of each index and the minimum element on the right of each index. Then, it counts the number of times the maximum on the left is less than or equal to the minimum on the right. The number of chunks is incremented by 1 when the maximum is equal to the minimum.

The main function first gets the input from the user, then calls the `maxChunksToSorted` function with the input array. The result is printed.