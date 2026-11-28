import heapq

def solve(rope_lengths):
    heap = [length]
    min_cost = 0
    
    while len(rope_lengths) > 1:
        length1, length2 = heapq.heappop(heap), heapq.heappop(heap)
        new_length = length1 + length2
        min_cost += new_length
        heapq.heappush(heap, new_length)
    
    return min_cost

def main():
    N = int(input().strip())
    rope_lengths = list(map(int, input().strip().split()))
    print(solve(rope_lengths))

if __name__ == "__main__":
    main()