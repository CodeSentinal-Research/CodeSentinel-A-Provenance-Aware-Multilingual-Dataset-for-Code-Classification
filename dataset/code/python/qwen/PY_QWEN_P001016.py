import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    arr = list(map(int, input_data[2:2+n]))
    
    dq = deque()
    result = []
    
    for i in range(n):
        # Remove indices out of window
        if dq and dq[0] < i - k + 1:
            dq.popleft()
            
        # Remove smaller elements from back
        while dq and arr[dq[-1]] <= arr[i]:
            dq.pop()
            
        dq.append(i)
        
        if i >= k - 1:
            result.append(arr[dq[0]])
            
    print(*result)

if __name__ == "__main__":
    solve()

