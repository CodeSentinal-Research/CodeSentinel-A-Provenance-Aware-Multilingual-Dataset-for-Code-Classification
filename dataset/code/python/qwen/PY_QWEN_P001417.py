import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    arr1 = list(map(int, input_data[idx:idx+n])); idx += n
    arr2 = list(map(int, input_data[idx:idx+m]))
    
    order_map = {val: i for i, val in enumerate(arr2)}
    
    def custom_sort_key(x):
        if x in order_map:
            return (0, order_map[x])
        else:
            return (1, x)
            
    arr1.sort(key=custom_sort_key)
    print(*arr1)

solve()

