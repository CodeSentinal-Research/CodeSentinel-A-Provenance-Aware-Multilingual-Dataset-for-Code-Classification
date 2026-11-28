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

def find_target_sum(root, k):
    seen = set()
    def inorder(node):
        if not node:
            return False
        if inorder(node.left):
            return True
        if k - node.val in seen:
            return True
        seen.add(node.val)
        return inorder(node.right)
        
    print("YES" if inorder(root) else "NO")

solve()

