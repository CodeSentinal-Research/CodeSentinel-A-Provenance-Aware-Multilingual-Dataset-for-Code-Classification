import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    k = int(input_data[idx]); idx += 1
    
    lists = []
    for _ in range(k):
        m = int(input_data[idx]); idx += 1
        lst = list(map(int, input_data[idx:idx+m]))
        idx += m
        lists.append(lst)
        
    # Min heap: (value, list_idx, element_idx)
    heap = []
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst[0], i, 0))
            
    min_range = float('inf')
    current_max = max(lst[0] for lst in lists if lst)
    start_val, end_val = 0, 0
    
    while heap:
        val, list_idx, elem_idx = heapq.heappop(heap)
        
        if current_max - val < min_range:
            min_range = current_max - val
            start_val = val
            end_val = current_max
            
        if elem_idx + 1 < len(lists[list_idx]):
            next_val = lists[list_idx][elem_idx + 1]
            current_max = max(current_max, next_val)
            heapq.heappush(heap, (next_val, list_idx, elem_idx + 1))
        else:
            break
            
    print(start_val, end_val)

if __name__ == "__main__":
    solve()

