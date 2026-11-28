Sure, here is the Python code for your problem:

def bst_pairs(trees, k):
    nodes = [node for tree in trees for node in tree.traverse()]
    pairs = [(i, j) for i in range(len(nodes)) for j in range(i + 1, len(nodes)) if nodes[i] + nodes[j] == k]
    return len(pairs)

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def traverse(self):
        if self.left:
            for node in self.left.traverse():
                yield node
        if self.right:
            for node in self.right.traverse():
                yield node
            yield self.value

def main():
    N1 = int(input().strip())
    trees1 = [BST(line.strip()) for line in input().strip().split('\n')[1:N1+1]]
    N2 = int(input().strip())
    trees2 = [BST(line.strip()) for line in input().strip().split('\n')[1:N2+1]]
    K = int(input().strip())
    print(bst_pairs(trees1 + trees2, K))

class BST:
    def __init__(self, line):
        nodes = line.split()
        self.root = Node(int(nodes[0]))
        for node in nodes[1:]:
            if 'L' in node:
                self.root.left = Node(int(node.split(' ')[1]))
            else:
                self.root.right = Node(int(node.split(' ')[1]))

if __name__ == "__main__":
    main()

This code defines a BST class for binary search trees, and a bst_pairs function for finding pairs in two binary search trees with a given sum. The main function reads the input, constructs the BSTs, and then prints the number of pairs.

Please note that the input should be in the format:
N1
tree1 nodes
tree2 nodes
K
The trees are constructed by splitting the lines of input on spaces, and constructing a binary search tree from the nodes. The nodes are represented as a string with 'L' indicating a left child, and 'R' indicating a right child.