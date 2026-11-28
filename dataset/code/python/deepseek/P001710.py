class Node:
    def __init__(self, x: int, left: 'Node' = None, right: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.left = left
        self.right = right
        self.random = random

def clone_tree(node: 'Node') -> 'Node':
    if node is None:
        return None
    
    clone = Node(node.val)
    clone.left = clone_tree(node.left)
    clone.right = clone_tree(node.right)
    clone.random = clone_tree(node.random)
    
    return clone

def main():
    n = int(input().strip())
    
    for _ in range(n):
        x, left, right, random = map(int, input().strip().split())
        node = Node(x, left=Node(left), right=Node(right), random=Node(random))
        
        clone = clone_tree(node)
        print(clone.val, clone.left.val, clone.right.val, clone.random.val)


if __name__ == "__main__":
    main()