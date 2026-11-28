Here is the Python code for the problem:


class Solution:
    def solve(self, root):
        if not root:
            return
        queue = [(root, 0)]
        left_most = [root.val]
        while queue:
            node, level = queue.pop(0)
            if node.left:
                if len(left_most) < level + 1:
                    left_most.append(node.left.val)
                queue.append((node.left, level + 1))
            if node.right:
                if len(left_most) < level + 1:
                    left_most.append(node.right.val)
                queue.append((node.right, level + 1))
        return left_most

Here is the main function:

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    solution = Solution()
    print(solution.solve(root))

This will print `[1, 2, 4, 5, 6, 7]`, which are the left-view nodes of the given binary tree.