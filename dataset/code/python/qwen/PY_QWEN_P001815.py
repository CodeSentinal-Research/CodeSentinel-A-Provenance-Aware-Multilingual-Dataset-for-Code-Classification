import sys

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

def tree_to_sorted_list(root):
    res = []
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        res.append(node.val)
        inorder(node.right)
    inorder(root)
    return res

def count_pairs_with_sum(l1, l2, k):
    i, j = 0, len(l2) - 1
    count = 0
    while i < len(l1) and j >= 0:
        s = l1[i] + l2[j]
        if s == k:
            # Handle duplicates
            c1 = 1
            while i + c1 < len(l1) and l1[i+c1] == l1[i]:
                c1 += 1
            c2 = 1
            while j - c2 >= 0 and l2[j-c2] == l2[j]:
                c2 += 1
            count += c1 * c2
            i += c1
            j -= c2
        elif s < k:
            i += 1
        else:
            j -= 1
    return count

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n1 = int(input_data[idx]); idx += 1
    vals1 = []
    for _ in range(n1):
        v = int(input_data[idx]); idx += 1
        vals1.append(v if v != -1 else None)
        
    n2 = int(input_data[idx]); idx += 1
    vals2 = []
    for _ in range(n2):
        v = int(input_data[idx]); idx += 1
        vals2.append(v if v != -1 else None)
        
    k = int(input_data[idx])
    
    t1 = build_tree(vals1)
    t2 = build_tree(vals2)
    
    l1 = tree_to_sorted_list(t1)
    l2 = tree_to_sorted_list(t2)
    
    print(count_pairs_with_sum(l1, l2, k))

solve()

