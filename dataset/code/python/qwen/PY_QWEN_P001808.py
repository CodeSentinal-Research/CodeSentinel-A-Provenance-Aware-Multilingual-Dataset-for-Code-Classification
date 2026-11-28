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

def sorted_list_to_bst(nums):
    if not nums:
        return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = sorted_list_to_bst(nums[:mid])
    root.right = sorted_list_to_bst(nums[mid+1:])
    return root

def merge_lists(l1, l2):
    i, j = 0, 0
    merged = []
    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:
            merged.append(l1[i])
            i += 1
        else:
            merged.append(l2[j])
            j += 1
    merged.extend(l1[i:])
    merged.extend(l2[j:])
    return merged

def level_order(root):
    if not root:
        return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

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
    
    merged = merge_lists(l1, l2)
    root = sorted_list_to_bst(merged)
    print(level_order(root))

solve()

