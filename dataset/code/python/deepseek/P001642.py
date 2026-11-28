Here is a Python solution for the problem. The code first creates a binary tree from the given input and then calculates the diameter of the tree.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert_level_order(arr, root, i, n): 
    if i < n: 
        temp = Node(arr[i])  
        root = temp 
  
        root.left = insert_level_order(arr, root.left, 2 * i + 1, n) 
  
        root.right = insert_level_order(arr, root.right, 2 * i + 2, n) 
        return root 
    return None

def diameter(root):
    if root is None:
        return 0

    lheight = height(root.left)
    rheight = height(root.right)

    ldiameter = diameter(root.left)
    rdiameter = diameter(root.right)

    return max(lheight + rheight + 1, max(ldiameter, rdiameter))

def height(node):
    if node is None:
        return 0
    else:
        return (max(height(node.left), height(node.right)) + 1)

def main():
    n = 7
    arr = [None] * n
    for i in range(n):
        arr[i] = int(input())
    root = insert_level_order(arr, None, 0, n)
    print(diameter(root))

if __name__ == "__main__":
    main()
This code will take the input for the number of nodes and the nodes themselves, insert them into a binary tree and then calculate and print the diameter of the binary tree.