import sys
sys.setrecursionlimit(500000)
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(nodes):
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    queue = [root]
    i = 1
    while queue and i < len(nodes):
        node = queue.pop(0)
        if i < len(nodes) and nodes[i] is not None:
            node.left = TreeNode(nodes[i])
            queue.append(node.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            node.right = TreeNode(nodes[i])
            queue.append(node.right)
        i += 1
    return root

def count_downward_paths_k(node, k):
    count = 0
    prefix_sum_count = defaultdict(int)
    prefix_sum_count[0] = 1
    
    def dfs(n, curr_sum):
        nonlocal count
        if not n:
            return
        curr_sum += n.val
        count += prefix_sum_count[curr_sum - k]
        prefix_sum_count[curr_sum] += 1
        dfs(n.left, curr_sum)
        dfs(n.right, curr_sum)
        prefix_sum_count[curr_sum] -= 1
        
    dfs(node, 0)
    return count

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    k = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    print(count_downward_paths_k(root, k))

solve()

