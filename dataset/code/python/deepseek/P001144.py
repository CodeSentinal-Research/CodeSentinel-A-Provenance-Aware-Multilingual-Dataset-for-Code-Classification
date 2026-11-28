def longest_increasing_subsequence(arr):
    n = len(arr)

    lis = [1] * n

    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    maximum = 0

    for i in range(len(lis)):
        maximum = max(maximum, lis[i])

    return maximum

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(longest_increasing_subsequence(arr))

if __name__ == "__main__":
    main()

This Python code uses the dynamic programming approach to solve the longest increasing subsequence problem. It first computes the longest increasing subsequence for every element in the array, then it finds the maximum of all these lengths.