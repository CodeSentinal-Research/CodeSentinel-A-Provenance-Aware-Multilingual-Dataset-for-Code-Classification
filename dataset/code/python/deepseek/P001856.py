Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root):
        if not root: return None
        prev = Node(None)
        self.head = prev
        self.inorder(root, prev)
        prev.right, self.head.right.left = self.head.right, prev
        self.head.right.right = None
        return self.head.right

    def inorder(self, node, prev):
        if node:
            self.inorder(node.left, prev)
            prev.right, node.left = node, prev
            prev = node
            self.inorder(node.right, prev)

def main():
    n = int(input())
    nodes = [int(input()) for _ in range(n)]
    tree = [Node(nodes[i]) for i in range(n) if nodes[i] is not None]
    for i in range(n):
        if i % 2 == 0:
            tree[i//2].left = tree[i]
        else:
            tree[i//2].right = tree[i]
    s = Solution()
    s.flatten(tree[0])
    cur = s.head
    while cur:
        print(cur.val)
        cur = cur.right

if __name__ == "__main__":
    main()

In the main function, we read the number of nodes and the values of the nodes. We create a list of nodes and then a binary search tree from this list. The `flatten` function is called with the root of the binary search tree to get the head of the circular doubly linked list. Finally, we print the values of the linked list.