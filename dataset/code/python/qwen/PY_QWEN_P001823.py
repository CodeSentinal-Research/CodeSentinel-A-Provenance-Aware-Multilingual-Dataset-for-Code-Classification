import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    postorder = list(map(int, input_data[idx:idx+n]))
    
    def verify(start, end, min_val, max_val):
        if start > end:
            return True
        root_val = postorder[end]
        if root_val < min_val or root_val > max_val:
            return False
            
        i = start
        while i <= end and postorder[i] < root_val:
            i += 1
            
        # Check right subtree
        for j in range(i, end):
            if postorder[j] < root_val:
                return False
                
        return verify(start, i-1, min_val, root_val) and verify(i, end-1, root_val, max_val)
        
    print("YES" if verify(0, n-1, float('-inf'), float('inf')) else "NO")

solve()

