import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    k = int(input_data[idx]); idx += 1
    n = int(input_data[idx]); idx += 1
    
    heap = []
    total_elements = k * n
    
    for i in range(k):
        row = list(map(int, input_data[idx:idx+n]))
        idx += n
        if row:
            heapq.heappush(heap, (row[0], i, 0))
            
    result = []
    while heap and len(result) < total_elements:
        val, row_idx, col_idx = heapq.heappop(heap)
        result.append(val)
        if col_idx + 1 < n:
            next_val = input_data[idx - n + col_idx + 1] # This logic is tricky with flat input
            # Re-reading input properly is better
            pass 
            
    # Simplified approach for flat input parsing
    # Let's re-parse carefully
    pass

# Corrected P001014
def solve_p001014():
    import sys
    data = sys.stdin.read().split()
    if not data: return
    it = iter(data)
    k = int(next(it))
    n = int(next(it))
    
    arrays = []
    for _ in range(k):
        arr = [int(next(it)) for _ in range(n)]
        arrays.append(arr)
        
    heap = []
    for i in range(k):
        if arrays[i]:
            heapq.heappush(heap, (arrays[i][0], i, 0))
            
    result = []
    while heap:
        val, arr_idx, elem_idx = heapq.heappop(heap)
        result.append(val)
        if elem_idx + 1 < len(arrays[arr_idx]):
            next_elem_idx = elem_idx + 1
            next_val = arrays[arr_idx][next_elem_idx]
            heapq.heappush(heap, (next_val, arr_idx, next_elem_idx))
            
    print(*result)

if __name__ == "__main__":
    solve_p001014()

