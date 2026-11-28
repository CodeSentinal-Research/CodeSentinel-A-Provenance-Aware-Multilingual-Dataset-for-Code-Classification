def max_product_subarray(n, arr):
    max_d = [0] * n
    min_d = [0] * n
    max_d[0] = arr[0]
    min_d[0] = arr[0]

    for i in range(1, n):
        if arr[i] < 0:
            max_d[i] = max(min_d[i-1]*arr[i], arr[i])
            min_d[i] = min(max_d[i-1]*arr[i], arr[i])
        else:
            max_d[i] = max(max_d[i-1]*arr[i], arr[i])
            min_d[i] = min(min_d[i-1]*arr[i], arr[i])

    return max(max_d)

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_product_subarray(n, arr))