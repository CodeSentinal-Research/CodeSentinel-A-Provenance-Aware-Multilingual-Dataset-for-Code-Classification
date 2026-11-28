Here is a Python solution for the given problem:

def minAdjacentSwaps(arr, K):
    indices = [i for i in range(len(arr)) if arr[i] == 1]
    indices = [(i, i - k + 1) for k in range(K, len(indices) + 1) for i in indices]
    indices = [i for i in indices if i[1] < 0]
    
    swaps = sum(max(0, i[1]) for i in indices)
    return swaps

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(minAdjacentSwaps(arr, K))

main()

This code first finds all the indices of K consecutive ones in the input array, then calculates the maximum number of adjacent swaps for each group of K consecutive ones. The result is the minimum number of swaps required to group K ones consecutively.