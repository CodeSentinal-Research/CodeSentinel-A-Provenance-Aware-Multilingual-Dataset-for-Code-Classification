Here's a Python solution with the main function and input handling.

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def listToTree(lst):
    if not lst: return None

    root = Node(lst[0])
    queue = [root]
    i = 1
    while i < len(lst):
        if lst[i] is not None:
            node = Node(lst[i])
            queue.append(node)
        else:
            queue.append(None)
        if i % 2 == 1:
            queue.append(None)
        i += 1

    while len(queue) is not 0:
        temp = queue.pop(0)
        if temp is not None:
            temp.left = queue.pop(0)
            if len(queue) is not 0:
                temp.right = queue.pop(0)
        else:
            if len(queue) is not 0:
                queue[0].left = queue.pop(0)
            if len(queue) is not 0:
                queue[0].right = queue.pop(0)

    return root

def sumNodes(root):
    if root is None:
        return 0

    left_sum = sumNodes(root.left)
    right_sum = sumNodes(root.right)

    root.val += left_sum + right_sum

    return root.val

def transform(root):
    sumNodes(root)

def printTree(root):
    if root is None:
        return

    print(root.val)
    printTree(root.left)
    printTree(root.right)

def main():
    n = int(input().strip())
    lst = list(map(int, input().strip().split()))
    root = listToTree(lst)
    transform(root)
    printTree(root)

if __name__ == "__main__":
    main()
This code first reads the number of nodes, the node values, and the tree structure from the input. The tree is then transformed into a binary tree by the `listToTree` function. The `sumNodes` function is then used to replace each node in the tree with the sum of all other nodes at the same level. Finally, the transformed tree is printed out.