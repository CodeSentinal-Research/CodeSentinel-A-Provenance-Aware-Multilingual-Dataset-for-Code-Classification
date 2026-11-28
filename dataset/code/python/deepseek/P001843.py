Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sortedListToBST(self, head):
        if not head:
            return None
        if not head.next:
            return Node(head.val)
        
        slow, fast = head, head.next.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        temp = slow.next
        slow.next = None
        node = Node(temp.val)
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(temp.next)
        return node

    def constructMaximumBinaryTree(self, nums):
        if not nums:
            return None
        max_value = max(nums)
        node = Node(max_value)
        max_index = nums.index(max_value)
        node.left = self.constructMaximumBinaryTree(nums[:max_index])
        node.right = self.constructMaximumBinaryTree(nums[max_index + 1:])
        return node

def main():
    nums = list(map(int, input().split()))[1:]
    n = nums[0]
    head = Node(nums[0])
    temp = head
    for num in nums[1:]:
        node = Node(num)
        temp.right = node
        temp = temp.right
        node.left = temp
    solution = Solution()
    root = solution.sortedListToBST(head)
    print(root.left.val, root.right.val)

if __name__ == "__main__":
    main()

This Python code first handles the input for the linked list from the standard input. Then it constructs a maximum binary tree from the sorted linked list. The solution uses recursion to find the maximum element and split the linked list into two parts. The left part of the linked list is recursively handled by the `sortedListToBST` function, and the right part is handled by the `constructMaximumBinaryTree` function. 

Please note that this code is for the problem statement and does not include all the details required in the problem. The input handling part is done manually.