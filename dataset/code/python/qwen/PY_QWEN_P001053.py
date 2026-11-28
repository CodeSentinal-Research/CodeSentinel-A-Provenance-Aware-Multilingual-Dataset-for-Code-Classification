import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    q = int(input_data[idx]); idx += 1
    
    heap = []
    output = []
    
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "INSERT":
            val = int(input_data[idx]); idx += 1
            heapq.heappush(heap, -val) # Max heap
        elif op == "DELETE":
            if heap:
                heapq.heappop(heap)
        elif op == "GET":
            if heap:
                output.append(str(-heap[0]))
            else:
                output.append("EMPTY")
                
    print("
".join(output))

if __name__ == "__main__":
    solve()

