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

def find_median(root):
    # Count nodes
    def count_nodes(node):
        if not node:
            return 0
        return 1 + count_nodes(node.left) + count_nodes(node.right)
        
    total = count_nodes(root)
    if total == 0:
        return None
        
    # Find kth element
    k = (total + 1) // 2 # 1-based index for median logic
    
    current_k = [0]
    result = [None]
    
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        current_k[0] += 1
        if current_k[0] == k:
            result[0] = node.val
            return
        if current_k[0] > k:
            return
        inorder(node.right)
        
    inorder(root)
    
    # If even, average of k and k+1? Problem usually implies single median or specific rule.
    # Let's assume standard median definition for odd/even.
    # If even, average of two middle elements.
    
    if total % 2 == 1:
        return result[0]
    else:
        # Need k and k+1
        val1 = result[0]
        current_k[0] = 0
        result[0] = None
        k2 = k + 1
        
        def inorder2(node):
            if not node:
                return
            inorder2(node.left)
            current_k[0] += 1
            if current_k[0] == k2:
                result[0] = node.val
                return
            if current_k[0] > k2:
                return
            inorder2(node.right)
            
        inorder2(root)
        val2 = result[0]
        return (val1 + val2) / 2

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
        
    root = build_tree(vals)
    med = find_median(root)
    if med is not None:
        if isinstance(med, float) and med.is_integer():
            print(int(med))
        else:
            print(med)
    else:
        print("")

solve()

