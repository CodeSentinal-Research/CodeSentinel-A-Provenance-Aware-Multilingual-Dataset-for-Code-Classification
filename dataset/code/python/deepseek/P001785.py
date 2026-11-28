Sure, here is a Python code snippet that implements a Depth-First Search (DFS) on the given binary tree to find the maximum independent set.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.independentSet = set()
        self.maxIndependentSet = set()

    def addNodes(self, nodes, data):
        if data == -1:
            return None
        node = Node(data)
        node.left = self.addNodes(nodes, data)
        node.right = self.addNodes(nodes, data)
        return node

    def maxIndependentSetUtil(self, node):
        if node is None:
            return 0

        including = self.values[node.data] + self.maxIndependentSetUtil(node.left.left) + self.maxIndependentSetUtil(node.right.left)
        excluding = self.maxIndependentSetUtil(node.left) + self.maxIndependentSetUtil(node.right)

        self.maxIndependentSet[node] = max(including, excluding)
        return self.maxIndependentSet[node]

    def maxIndependentSet(self, nodes):
        if nodes is None:
            return 0

        self.values = [-1] * 100000
        self.maxIndependentSetUtil(nodes)
        return self.maxIndependentSet[nodes]


def main():
    input_nodes = list(map(int, input().strip().split()))[1:]
    nodes = Solution()
    nodes.addNodes(nodes, input_nodes)
    print(nodes.maxIndependentSet(nodes))


if __name__ == "__main__":
    main()
This code first creates a binary tree from the input nodes. The `maxIndependentSet` function is used to find the maximum independent set. The `maxIndependentSetUtil` function is a helper function that uses depth-first search to find the maximum independent set. The `addNodes` function is a helper function that adds a node to the binary tree.