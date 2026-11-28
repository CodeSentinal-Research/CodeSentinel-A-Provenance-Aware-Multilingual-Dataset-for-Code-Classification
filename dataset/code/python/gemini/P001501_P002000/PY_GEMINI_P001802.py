class ListNode:
    def __init__(self, val=0, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        """Sorts the input array into ordered sequence."""
        def count_nodes(node):
            c = 0
            while node:
                c += 1
                node = node.next
            return c

        n = count_nodes(head)
        cur = head

        def build(count):
            nonlocal cur
            if count <= 0:
                return None
            left = build(count // 2)
            root = TreeNode(cur.val)
            cur = cur.next
            root.left = left
            root.right = build(count - count // 2 - 1)
            return root

        return build(n)