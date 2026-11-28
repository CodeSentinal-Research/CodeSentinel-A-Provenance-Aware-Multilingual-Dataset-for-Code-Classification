class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        result, current_level, next_level = [], [root], []

        while current_level:
            result.append([node.val for node in current_level])
            for node in current_level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            current_level, next_level = next_level, current_level

        return result