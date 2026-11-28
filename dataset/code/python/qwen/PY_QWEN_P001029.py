import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    # Convert min heap to max heap by building max heap from array
    # Negate, heapify, negate back
    max_heap = [-x for x in arr]
    heapq.heapify(max_heap)
    result = [-x for x in max_heap]
    print(*result)

if __name__ == "__main__":
    solve()

