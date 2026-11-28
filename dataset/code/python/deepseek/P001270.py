def min_operations(n, arr):
    operations = 0
    for i in range(n):
        if arr[i] > 0 and arr[i] <= arr[i-1]:
            operations += (arr[i-1] - arr[i] + 1 + arr[i] - 1)
            arr[i] = 0
    return operations

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(min_operations(n, arr))

if __name__ == "__main__":
    main()