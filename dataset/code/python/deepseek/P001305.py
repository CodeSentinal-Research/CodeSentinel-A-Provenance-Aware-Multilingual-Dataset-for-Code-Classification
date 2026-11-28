import heapq
import sys

def solve():
    N = int(sys.stdin.readline().strip())
    freqs = [int(x) for x in sys.stdin.readline().strip().split()]

    heap = [[freq, [symbol, '']] for symbol, freq in enumerate(freqs)]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        for pair in left[1:]:
            pair[1] = '0' + pair[1]
        for pair in right[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [left[0] + right[0]] + left[1:] + right[1:])

    root = heap[0][1]
    print(sum([len(symbol[1]) * freq for freq, symbol in heap]))

if __name__ == "__main__":
    solve()