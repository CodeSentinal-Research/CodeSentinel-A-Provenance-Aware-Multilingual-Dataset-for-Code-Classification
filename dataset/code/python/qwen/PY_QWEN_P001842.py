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

def find_union(l1, l2):
    i, j = 0, 0
    res = []
    while i < len(l1) and j < len(l2):
        if l1[i] == l2[j]:
            res.append(l1[i])
            i += 1
            j += 1
        elif l1[i] < l2[j]:
            res.append(l1[i])
            i += 1
        else:
            res.append(l2[j])
            j += 1
    res.extend(l1[i:])
    res.extend(l2[j:])
    return res

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
        
    t1 = build_tree(vals1)
    t2 = build_tree(vals2)
    
    l1 = tree_to_sorted_list(t1)
    l2 = tree_to_sorted_list(t2)
    
    print(*find_union(l1, l2))

solve()

