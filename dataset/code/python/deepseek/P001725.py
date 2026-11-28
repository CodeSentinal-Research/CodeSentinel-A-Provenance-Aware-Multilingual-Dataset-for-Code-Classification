class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def solve(root, k):
    counts = dict()
    counts[0] = 1
    helper(root, 0, k, counts)
    return counts[0]

def helper(node, curr_sum, k, counts):
    if node is None:
        return
    curr_sum += node.value
    if curr_sum not in counts:
        counts[curr_sum] = 0
    counts[curr_sum] += 1
    if node.left is None and node.right is None:
        if curr_sum == k:
            counts[0] += 1
    else:
        helper(node.left, curr_sum, k, counts)
        helper(node.right, curr_sum, k, counts)

def main():
    n = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    root = None
    stack = []
    for i in range(n):
        if nodes[i] == -1:
            if stack:
                parent = stack.pop()
                if stack:
                    parent.right = None
                if not stack:
                    parent.left = None
            else:
                root = None
        else:
            if not stack:
                root = Node(nodes[i])
                stack.append(root)
            else:
                parent = stack[-1]
                if nodes[i] < parent.value:
                    if parent.left is None:
                        parent.left = Node(nodes[i])
                    else:
                        parent = parent.left
                else:
                    if parent.right is None:
                        parent.right = Node(nodes[i])
                    else:
                        parent = parent.right
                stack.append(parent)
    k = int(input().strip())
    print(solve(root, k))

if __name__ == '__main__':
    main()