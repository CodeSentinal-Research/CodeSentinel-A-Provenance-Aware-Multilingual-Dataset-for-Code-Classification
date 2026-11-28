def solve(arr, x):
    prefix_sums = [0] * len(arr)
    prefix_sums[0] = arr[0]
    for i in range(1, len(arr)):
        prefix_sums[i] = prefix_sums[i - 1] + arr[i]

    for i in range(len(arr)):
        if prefix_sums[i] >= x:
            return i
    return -1

def main():
    N, X = map(int, input().split())
    arr = list(map(int, input().split()))
    print(solve(arr, X))

if __name__ == "__main__":
    main()