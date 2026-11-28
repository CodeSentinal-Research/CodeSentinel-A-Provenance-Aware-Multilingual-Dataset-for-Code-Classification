Here is the Python code:

def isBalanced(root):
    def height(root):
        if not root:
            return 0
        left_height = height(root.left)
        if left_height == -1:
            return -1
        right_height = height(root.right)
        if right_height == -1:
            return -1
        if abs(left_height - right_height) > 1:
            return -1
        return max(left_height, right_height) + 1

    return height(root) != -1

The function `isBalanced` is checking if the binary tree is height balanced. The `height` function is calculating the height of each node. If the current node is None, the height is 0. If the left child is not None, we calculate the height of the left child. If the left child's height is -1, it means that the tree is not balanced, so we return -1. Similar process is applied to the right child. If the absolute difference between the left and right heights is greater than 1, it means that the tree is not balanced, so we return -1. Otherwise, we return the maximum height plus 1. The main function is checking if the root is None, if it is not None, we call the `height` function and return the result. If the result is not -1, we return True; otherwise, we return False.