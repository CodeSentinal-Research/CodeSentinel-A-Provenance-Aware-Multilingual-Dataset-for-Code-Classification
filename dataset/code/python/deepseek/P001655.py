Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

head = None

def flatten(root):
    global head
    if root is None:
        return
    flatten(root.left)
    temp = root
    root.left = None
    if head is None:
        head = temp
    else:
        current = head
        while current.right is not None:
            current = current.right
        current.right = temp
        temp.left = current
    flatten(root.right)

def printList(head):
    current = head
    while current is not None:
        print(current.val, end=" ")
        current = current.right

def read_input():
    n = int(input().strip())
    nodes = [None] * (n + 2)
    for i in range(1, n + 1):
        line = input().strip().split()
        nodes[i] = Node(int(line[0]))
        if i > 1:
            nodes[int(line[1])].left = nodes[i]
            nodes[int(line[2])].right = nodes[i]
    return nodes[1]

def main():
    root = read_input()
    flatten(root)
    printList(head)

if __name__ == "__main__":
    main()

In this code, we define a Node class to represent the nodes of the binary tree. The flatten function is used to convert the binary tree to a doubly linked list, and the printList function is used to print the doubly linked list. The read_input function is used to read the input and convert it into a binary tree. The main function is the entry point of the program.