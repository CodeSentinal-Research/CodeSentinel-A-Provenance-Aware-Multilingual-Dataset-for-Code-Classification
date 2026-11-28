import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    keys = list(map(int, input_data[idx:idx+n])); idx += n
    freqs = list(map(int, input_data[idx:idx+n]))
    
    # Construct Optimal BST structure?
    # Problem asks to "Construct".
    # Output format unspecified, likely level order or similar.
    # Using DP to find root, then recurse.
    
    dp = [[0]*n for _ in range(n)]
    root_table = [[0]*n for _ in range(n)]
    
    for length in range(1, n+1):
        for i in range(n-length+1):
            j = i + length - 1
            dp[i][j] = float('inf')
            sum_freq = sum(freqs[i:j+1])
            for r in range(i, j+1):
                cost = (dp[i][r-1] if r > i else 0) + (dp[r+1][j] if r < j else 0) + sum_freq
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    root_table[i][j] = r
                    
    # Build tree from root_table
    class TreeNode:
        def __init__(self, val):
            self.val = val
            self.left = None
            self.right = None
            
    def build_optimal(i, j):
        if i > j:
            return None
        r = root_table[i][j]
        node = TreeNode(keys[r])
        node.left = build_optimal(i, r-1)
        node.right = build_optimal(r+1, j)
        return node
        
    root = build_optimal(0, n-1)
    
    # Print level order
    if not root:
        print("")
        return
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    print(" ".join(res))

solve()

