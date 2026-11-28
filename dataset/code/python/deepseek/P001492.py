def find_closest(arr, n, k, x):
    left = x
    right = x

    while left < n and arr[left] <= x:
        left += 1

    if left >= n:
        return -1

    while right + 1 < n and arr[right + 1] <= x:
        right += 1

    res = arr[left:right+1]

    res.sort(key=lambda y: (y, arr.index(y)))

    return res[:k]

def main():
    N, K, X = map(int, input().split())
    arr = sorted(map(int, input().split()))
    print(' '.join(map(str, find_closest(arr, N, K, X))))

if __name__ == '__main__':
    main()