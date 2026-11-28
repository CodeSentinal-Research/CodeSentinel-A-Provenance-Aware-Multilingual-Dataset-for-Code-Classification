import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    preorder = list(map(int, input_data[idx:idx+n]))
    
    if not preorder:
        print("YES")
        return
        
    stack = []
    lower_bound = float('-inf')
    
    for val in preorder:
        if val < lower_bound:
            print("NO")
            return
        while stack and stack[-1] < val:
            lower_bound = stack.pop()
        stack.append(val)
        
    print("YES")

solve()

