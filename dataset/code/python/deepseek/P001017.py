import heapq

def solve(n, lengths):
    heap = [length for length in lengths]
    heapq.heapify(heap)
    total = 0
    while len(heap) > 1:
        length1 = heapq.heappop(heap)
        length2 = heapq.heappop(heap)
        total += length1 + length2
        heapq.heappush(heap, length1 + length2)
    return total

def main():
    n = int(input().strip())
    lengths = list(map(int, input().strip().split()))
    print(solve(n, lengths))

if __name__ == "__main__":
    main()
This Python code first defines a function `solve` that implements the Kruskal algorithm for finding the minimum spanning tree of a graph. The `main` function handles the input and output, taking care of the constraint that the rope lengths must be non-negative.