Here is the Python code:

def count_subarrays(arr, k):
    n = len(arr)
    count = 0
    for i in range(n):
        dist_count = {}
        unique_count = 0
        for j in range(i, n):
            if arr[j] in dist_count:
                dist_count[arr[j]] += 1
            else:
                dist_count[arr[j]] = 1
                unique_count += 1
            if unique_count == k:
                count += 1
            elif unique_count > k:
                break
    return count

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_subarrays(arr, k))

if __name__ == "__main__":
    main()

This code reads the array size `n` and the number of distinct elements `k`, then reads the array. The function `count_subarrays` calculates and returns the number of valid subarrays with exactly `k` distinct elements. The `main` function handles input and output.