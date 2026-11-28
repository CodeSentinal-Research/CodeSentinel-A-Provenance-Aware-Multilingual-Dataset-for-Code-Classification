def minDiff(arr, k):
    arr.sort()
    min_diff = arr[k-1] - arr[0]
    for i in range(k, len(arr)):
        min_diff = min(min_diff, arr[i] - arr[i-k+1])
    return min_diff

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(minDiff(arr, k))

if __name__ == "__main__":
    main()