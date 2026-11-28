def min_difference(N, K, arr):
    min_diff = float('inf')
    for i in range(N - K + 1):
        max_element = max(arr[i:i + K])
        min_element = min(arr[i:i + K])
        diff = max_element - min_element
        min_diff = min(min_diff, diff)
    return min_diff

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(min_difference(N, K, arr))

if __name__ == '__main__':
    main()