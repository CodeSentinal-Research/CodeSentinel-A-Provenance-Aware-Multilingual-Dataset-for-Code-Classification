def maxChunksToSorted(arr):
    n = len(arr)
    max_right = [0] * n
    max_right[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        max_right[i] = max(max_right[i + 1], arr[i])

    chunks = 0
    left_max = 0
    for i in range(n - 1):
        left_max = max(left_max, arr[i])
        if left_max <= max_right[i + 1]:
            chunks += 1

    return chunks

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxChunksToSorted(arr))

if __name__ == "__main__":
    main()