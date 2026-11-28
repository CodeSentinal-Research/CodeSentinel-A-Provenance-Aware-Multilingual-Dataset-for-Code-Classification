def maxChunksToSorted(arr):
    max_heap = []
    chunks = 0
    for num in arr:
        if max_heap and num > max_heap[0]:
            chunks += 1
        heapq.heappush(max_heap, num)
    return chunks

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxChunksToSorted(arr))

if __name__ == "__main__":
    main()