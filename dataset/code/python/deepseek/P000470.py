def find_min_diff(N, target, arr):
    min_diff = abs(arr[1] - arr[0])
    min_element = min(arr[0], arr[1])

    for i in range(1, N-1):
        diff = abs(arr[i+1] - arr[i])
        if diff < min_diff:
            min_diff = diff
            min_element = min(arr[i+1], arr[i])

    return min_element

def main():
    N, target = map(int, input().split())
    arr = list(map(int, input().split()))
    result = find_min_diff(N, target, arr)
    print(result)

if __name__ == "__main__":
    main()