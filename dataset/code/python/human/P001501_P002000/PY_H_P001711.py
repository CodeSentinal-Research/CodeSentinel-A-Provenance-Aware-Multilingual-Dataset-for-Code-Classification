"""
Problem: Check for Children Sum Property in a Binary Tree

Description:
Given a binary tree, check whether it satisfies the Children Sum Property.
A node is said to follow this property if the value of the node is equal to
the sum of the values of its left and right children. Leaf nodes and empty
trees are considered valid.

Optimal Approach:
Use a recursive traversal (DFS). For each node:
- If it is a leaf node, return True.
- Otherwise, check if:
    node.data == (left_child.data if exists else 0) +
                 (right_child.data if exists else 0)
- Recursively verify the property for left and right subtrees.

Time Complexity: O(N), where N is the number of nodes.
Space Complexity: O(H), where H is the height of the tree (recursion stack).

Example:
Tree:
        10
       /  \
      8    2
     / \    \
    3   5    2

Explanation:
- 10 = 8 + 2
- 8 = 3 + 5
- 2 = 0 + 2
Hence, the tree satisfies the Children Sum Property.
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def check_children_sum(root):
    # An empty tree or a leaf node satisfy property
    if root is None or (root.left is None and root.right is None):
        return True

    # Get Left and Right child values (0 if child not exist)
    left_val = root.left.data if root.left else 0
    right_val = root.right.data if root.right else 0

    # check current and recursively chech subtrees
    return (
        root.data == left_val + right_val
        and check_children_sum(root.left)
        and check_children_sum(root.right)
    )


root = Node(10)
root.left = Node(8)
root.right = Node(2)
root.left.left = Node(3)
root.left.right = Node(5)
root.right.left = Node(0)
root.right.right = Node(2)

print(check_children_sum(root))
