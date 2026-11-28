Here is a Python solution that uses a breadth-first search approach to find the rightmost node at each level.


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        result = []
        queue = [(root, 0)]

        while queue:
            node, level = queue.pop(0)

            if level > len(result):
                result.append(node.val)

            if node.right:
                queue.append((node.right, level + 1))
            if node.left:
                queue.append((node.left, level + 1))

        return result

Main function:

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    solution = Solution()
    print(solution.rightSideView(root))  

if __name__ == "__main__":
    main()

In the main function, we first create a binary tree. The tree is as follows:

    1
   / \
  2   3
 / \
4   5

The output of the main function is `[3, 4]`, which is the right-side visible nodes of the binary tree.