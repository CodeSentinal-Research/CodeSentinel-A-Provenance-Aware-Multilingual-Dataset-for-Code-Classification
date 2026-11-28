Here is the Python code to solve the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def zigzagLevelOrder(root):
    if not root:
        return []

    result = []
    current_level = [root]
    left_to_right = True

    while current_level:
        next_level = []
        temp_values = [node.val for node in current_level]
        if left_to_right:
            result.append(temp_values)
        else:
            result.append(temp_values[::-1])

        for node in current_level:
            if node.left:
                next_level.append(node.left)
            if node.right:
                next_level.append(node.right)

        left_to_right = not left_to_right
        current_level = next_level

    return result

In this code, we first check if the root node is None, then return an empty list if so. Then, we initialize result to be an empty list and current level to be a list with the root node only. We also initialize left_to_right to be True, indicating that we want to traverse the tree from left to right.

We start a loop that continues until current_level is empty. In each iteration of the loop, we calculate the next level as a list of the values of the current level in the corresponding order (from left to right or from right to left). We then set current_level to be the next level and set left_to_right to be the opposite of its current value.

Finally, we return the result list.